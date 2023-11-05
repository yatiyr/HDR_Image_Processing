#include <Precomp.h>
#include "Image.h"
#include <glad/glad.h>

namespace HDR_IP
{
	Image::Image(const char* filePath)
	{
		HDR_IP_INFO("Loading image");

		try
		{
			stbi_set_flip_vertically_on_load(1);

			std::filesystem::path fP(filePath);

			m_Name = fP.filename().string();
			m_Data = (char*)stbi_load(filePath, &m_Width, &m_Height, &m_Channels, 0);

			GLenum internalFormat = 0, dataFormat = 0;

			if (m_Channels == 4)
			{
				internalFormat = GL_RGBA8;
				dataFormat = GL_RGBA;
			}
			else if (m_Channels == 3)
			{
				internalFormat = GL_RGB8;
				dataFormat = GL_RGB;
			}
			else if (m_Channels == 1)
			{
				internalFormat = GL_R8;
				dataFormat = GL_RED;
			}

			glCreateTextures(GL_TEXTURE_2D, 1, &m_OpenGLID);
			glBindTexture(GL_TEXTURE_2D, m_OpenGLID);

			glTextureParameteri(m_OpenGLID, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTextureParameteri(m_OpenGLID, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTextureParameteri(m_OpenGLID, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTextureParameteri(m_OpenGLID, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTextureStorage2D(m_OpenGLID, 1, internalFormat, m_Width, m_Height);
			glTextureSubImage2D(m_OpenGLID, 0, 0, 0, m_Width, m_Height, dataFormat, GL_UNSIGNED_BYTE, m_Data);
			//glTexImage2D(GL_TEXTURE_2D, 0, dataFormat, m_Width, m_Height, 0, dataFormat, GL_UNSIGNED_BYTE, m_Data);


			// Parse Exif Info
			std::ifstream file(filePath, std::ifstream::binary);

			TinyEXIF::EXIFInfo exifInfo(file);
			if (exifInfo.Fields)
			{
				HDR_IP_TRACE("\tImage Description: {0}", exifInfo.ImageDescription);
				HDR_IP_TRACE("\tImage Resolution: ({0},{1})", exifInfo.ImageWidth, exifInfo.ImageHeight);
				HDR_IP_TRACE("\tCamera Model: {0} - {1}", exifInfo.Make, exifInfo.Model);
				HDR_IP_TRACE("\tFocal Length: {0}", exifInfo.FocalLength);
			}

			m_ExifInfo = exifInfo;


			Pixel rp = GetPixel(0, 0);
			HDR_IP_TRACE("RGB values for pixel 0 0 : ({0}, {1}, {2})", rp.r, rp.g, rp.b);

		}
		catch (const std::exception&)
		{
			HDR_IP_ERROR("\tFailed to load the Image");
		}
	}

	Ref<Image> Image::CreateImage(const char* filePath)
	{
		return std::make_shared<Image>(filePath);
	}

	Image::~Image()
	{
		free(m_Data);
		glDeleteTextures(1, &m_OpenGLID);
	}

	std::string Image::GetName() const
	{
		return m_Name;
	}

	int Image::GetWidth() const
	{
		return m_Width;
	}

	int Image::GetHeight() const
	{
		return m_Height;
	}

	int Image::GetChannels() const
	{
		return m_Channels;
	}

	uint32_t Image::GetOpenGLID() const
	{
		return m_OpenGLID;
	}

	TinyEXIF::EXIFInfo Image::GetEXIFInfo() const
	{
		return m_ExifInfo;
	}

	Pixel Image::GetPixel(int i, int j)
	{
		Pixel resultPixel {0,0,0,0};
		if (i >= m_Width || i < 0)
		{
			HDR_IP_ERROR("Out of bounds. Image Width {0}, i value {1} ", m_Width, i);
			return resultPixel;
		}
		
		if (j >= m_Width || j < 0)
		{
			HDR_IP_ERROR("Out of bounds. Image Height {0}, j value {1} ", m_Height, j);
			return resultPixel;
		}

		resultPixel.r = m_Data[j * m_Width * m_Channels + i * m_Channels + 0];
		resultPixel.g = m_Data[j * m_Width * m_Channels + i * m_Channels + 1];
		resultPixel.b = m_Data[j * m_Width * m_Channels + i * m_Channels + 2];
		if (m_Channels > 3)
			resultPixel.a = m_Data[j * m_Width * m_Channels + i * m_Channels + 3];
		else
			resultPixel.a = 0;

		return resultPixel;

	}

}