#pragma once

#include <cstdint>
#include <stb_image.h>
#include <HDR_IP/System/CoreSystem/Application.h>
#include <glm/glm.hpp>
#include <TinyEXIF.h>

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

		Pixel GetPixel(int i, int j);
	public:
		static Ref<Image> CreateImage(const char* filePath);

	// Getters and Setters
	public:
		std::string GetName() const;
		int GetWidth() const;
		int GetHeight() const;
		int GetChannels() const;
		uint32_t GetOpenGLID() const;
		TinyEXIF::EXIFInfo GetEXIFInfo() const;
	private:
		std::string m_Name;
		int m_Width;
		int m_Height;
		int m_Channels;

		uint32_t m_OpenGLID;

		TinyEXIF::EXIFInfo m_ExifInfo;
		char* m_Data;
	};
}