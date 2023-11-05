#include <Precomp.h>
#include "Image_RRC.h"
#include <TinyEXIF.h>
#include <queue>

#include <Eigen/Dense>

namespace HDR_IP
{

	struct Image_RRCData
	{

		// Pixel neighbour val
		int pnv = 50;

		std::vector<std::vector<float>> pixelsR;
		std::vector<std::vector<float>> pixelsG;
		std::vector<std::vector<float>> pixelsB;

		std::vector<float> exposureVals;
	} s_Image_RRCData;

	struct PixelVariance
	{
		float pixel;
		float variance;
	};

	void Image_RRC::RecoverResponseCurve(std::vector<Ref<Image>>& images)
	{
		// Clear the data
		s_Image_RRCData.exposureVals.clear();
		s_Image_RRCData.pixelsR.clear();
		s_Image_RRCData.pixelsG.clear();
		s_Image_RRCData.pixelsB.clear();

		// Resize the vectors
		s_Image_RRCData.pixelsR.resize(images.size());
		s_Image_RRCData.pixelsG.resize(images.size());
		s_Image_RRCData.pixelsB.resize(images.size());

		// TODO: Calculate neighbour val from image size

		HDR_IP_WARN("---------- RECOVERING THE RESPONSE CURVE ----------");

		// First we log image properties
		HDR_IP_TRACE("\t1 --Image Properties-- ");

		for (const auto& image : images)
		{
			TinyEXIF::EXIFInfo imageInfo = image->GetEXIFInfo();
			HDR_IP_INFO("\tName              : {0}", image->GetName());
			HDR_IP_INFO("\t\tExposure Time   : {0}", imageInfo.ExposureTime);
			HDR_IP_INFO("\t\tF Number        : {0}", imageInfo.FNumber);
			HDR_IP_INFO("\t\tISO             : {0}", imageInfo.ISOSpeedRatings);
			HDR_IP_INFO("\t\tShutter Speed   : {0}", imageInfo.ShutterSpeedValue);
			HDR_IP_INFO("\t\tBrightness      : {0}", imageInfo.BrightnessValue);
			HDR_IP_INFO("\t\tAperture Val    : {0}", imageInfo.ApertureValue);
		}
		
		// Now we need to sample N Pixels for each image
		for (int i=0; i<images.size(); i++)
		{
			TinyEXIF::EXIFInfo imageInfo = images[i]->GetEXIFInfo();
			// Get Samples for each image
			std::vector<std::vector<float>> samples = GetSamplePixelsFromImage(images[i], 300);
			s_Image_RRCData.pixelsR[i] = samples[0];
			s_Image_RRCData.pixelsG[i] = samples[1];
			s_Image_RRCData.pixelsB[i] = samples[2];

			s_Image_RRCData.exposureVals.push_back((float)imageInfo.ExposureTime);
		}

		SolveSystem();

	}

	std::vector<std::vector<float>> Image_RRC::GetSamplePixelsFromImage(Ref<Image> image, int n)
	{
		std::vector<std::vector<float>> result;
		// Resize the result as 3 because we need 3 channels
		result.resize(3);

		// Calculate neigbourhood variance of each pixel and variance for each channel
		auto comp = [](PixelVariance a, PixelVariance b) { return a.variance < b.variance; };
		std::priority_queue<PixelVariance, std::vector<PixelVariance>, decltype(comp)> pqR(comp);
		std::priority_queue<PixelVariance, std::vector<PixelVariance>, decltype(comp)> pqG(comp);
		std::priority_queue<PixelVariance, std::vector<PixelVariance>, decltype(comp)> pqB(comp);

		int imageHeight = image->GetHeight();
		int imageWidth = image->GetWidth();

		for (int i = 0; i < imageHeight; i++)
		{
			for (int j = 0; j < imageWidth; j++)
			{
				HDR_IP_WARN("Pixel: ({0}, {1})", j, i);
				Pixel px = image->GetPixel(j, i);
				if ((px.r <= 5 && px.g <= 5 && px.b <= 5) || (px.r >= 250 && px.g >= 250 && px.b >= 250))
				{
					j += 10;

					PixelVariance pvR{ px.r, 100000.0 };
					PixelVariance pvG{ px.g, 100000.0 };
					PixelVariance pvB{ px.b, 100000.0 };

					// Push pixel variance couples to min heaps
					pqR.push(pvR); pqG.push(pvG); pqB.push(pvB);
					continue;
				}
					
				std::vector<Pixel> neighborhoodPixels;
				int val = s_Image_RRCData.pnv / 2;

				// Get Obtainable pixels in the neighborhood
				for (int k = -val; k <= val; k++)
				{
					if (i + k < 0 || i + k >= imageHeight)
						continue;

					for (int l = -val; l <= val; l++)
					{
						if (j + l < 0 || j + l >= imageWidth)
							continue;

						neighborhoodPixels.push_back(image->GetPixel(j + l, i + k));
					}
				}

				// Get mean for every channel
				float rMean = 0.0f, gMean = 0.0f, bMean = 0.0f;
				int count = (val + 1) * (val + 1);

				for (auto& pixel : neighborhoodPixels)
				{
					rMean += pixel.r; gMean += pixel.g; bMean += pixel.b;
				}

				rMean /= count; gMean /= count; bMean /= count;

				// Variance for each channel
				float rVariance = 0.0f;
				float gVariance = 0.0f;
				float bVariance = 0.0f;

				for (auto& pixel : neighborhoodPixels)
				{
					rVariance += std::pow((pixel.r - rMean), 2);
					gVariance += std::pow((pixel.g - gMean), 2);
					bVariance += std::pow((pixel.b - bMean), 2);
				}

				rVariance /= count; gVariance /= count; bVariance /= count;

				// Pixel variance couples for each channel
				PixelVariance pvR { px.r, rVariance };
				PixelVariance pvG { px.g, gVariance };
				PixelVariance pvB { px.b, bVariance };

				// Push pixel variance couples to min heaps
				pqR.push(pvR); pqG.push(pvG); pqB.push(pvB);

				j += imageWidth / 50;
			}

			i += imageHeight / 50;
		}

		// Get n samples from each min heap and populate the resulting part
		for (int i = 0; i < n; i++)
		{
			result[0].push_back(pqR.top().pixel); // RED
			result[1].push_back(pqG.top().pixel); // GREEN
			result[2].push_back(pqB.top().pixel); // BLUE

			pqR.pop(); pqG.pop(); pqB.pop(); // pop all channels
		}

		return result;
	}

	void Image_RRC::SolveSystem()
	{
		Eigen::MatrixXf A = Eigen::MatrixXf::Random(3, 2);
		std::cout << "Here is the matrix A:\n" << A << std::endl;
		Eigen::VectorXf b = Eigen::VectorXf::Random(3);
		std::cout << "Here is the right hand side b:\n" << b << std::endl;
		std::cout << "The least-squares solution is:\n"
			<< A.bdcSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(b) << std::endl;
	}

	// Weighting function
	float Image_RRC::W(float val)
	{
		// Zmin -> 0
		// Zmax -> 255
		float comp = 1.0f / 2.0f * (255.0f);

		if (val <= comp)
		{
			return val;
		}
		else
		{
			return 255 - val;
		}
	}
}