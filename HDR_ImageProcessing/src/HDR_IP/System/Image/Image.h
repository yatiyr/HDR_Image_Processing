#pragma once

#include <cstdint>
#include <stb_image.h>
#include <HDR_IP/System/CoreSystem/Application.h>
#include <glm/glm.hpp>

namespace HDR_IP
{

	struct Pixel
	{
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;
	};

	class Image
	{
	public:
		Image(const char* filePath);

		~Image();

		int GetWidth();
		int GetHeight();
		int GetChannels();

		Pixel GetPixel(int i, int j);
	public:
		static Ref<Image> CreateImage(const char* filePath);
	private:
		int m_Width;
		int m_Height;
		int m_Channels;

		uint32_t m_OpenGLID;

		char* m_Data;
	};
}