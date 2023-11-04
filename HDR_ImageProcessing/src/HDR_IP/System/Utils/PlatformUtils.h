#pragma once

#include <string>

namespace HDR_IP
{
	class FileDialogs
	{
	public:
		// They return empty string if cancelled
		static std::string OpenFile(const char* filter);
		static std::string SaveFile(const char* filter);
	};
}