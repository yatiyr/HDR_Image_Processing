#pragma once

#include <HdrIp.h>
#include <HDR_IP/System/Image/Image.h>
#include <filesystem>

namespace HDR_IP
{
	class Image_RRC
	{
	public:
		static void RecoverResponseCurve(std::vector<Ref<Image>>& images);
		
		static std::vector<float>& GetResponseCurveR();
		static std::vector<float>& GetResponseCurveG();
		static std::vector<float>& GetResponseCurveB();
		static std::vector<float>& GetPixelValueFunc();

	private:
		static std::vector<std::vector<float>> GetSamplePixelsFromImage(Ref<Image> image, int n);
		static std::vector<float> SolveSystem(std::vector<std::vector<float>> pixels, std::vector<float> logDeltaT, float l);
		static float W(float val);

		
	};
}