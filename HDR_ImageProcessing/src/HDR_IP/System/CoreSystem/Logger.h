#pragma once

#include <HDR_IP/System/CoreSystem/Core.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/fmt/ostr.h>

// Log macros
#define HDR_IP_FATAL(...) ::HDR_IP::Logger::GetLogger()->critical(__VA_ARGS__);
#define HDR_IP_ERROR(...) ::HDR_IP::Logger::GetLogger()->error(__VA_ARGS__);
#define HDR_IP_WARN(...)  ::HDR_IP::Logger::GetLogger()->warn(__VA_ARGS__);
#define HDR_IP_INFO(...)  ::HDR_IP::Logger::GetLogger()->info(__VA_ARGS__);
#define HDR_IP_TRACE(...) ::HDR_IP::Logger::GetLogger()->trace(__VA_ARGS__);

#define HDR_IP_FLUSH_TRACE() ::GP::Logger::GetLogger()->flush_on(spdlog::level::trace);

namespace HDR_IP
{
	class Logger
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetLogger()
		{
			return m_Logger;
		}

	private:
		static Ref<spdlog::logger> m_Logger;

	};
}