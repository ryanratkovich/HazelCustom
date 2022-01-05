#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace HazelCustom
{
	class HAZEL_CUSTOM_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define HCZ_CORE_TRACE(...)    ::HazelCustom::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HCZ_CORE_INFO(...)     ::HazelCustom::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HCZ_CORE_WARN(...)     ::HazelCustom::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HCZ_CORE_ERROR(...)    ::HazelCustom::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HCZ_CORE_FATAL(...)    ::HazelCustom::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define HCZ_TRACE(...)         ::HazelCustom::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HCZ_INFO(...)          ::HazelCustom::Log::GetClientLogger()->info(__VA_ARGS__)
#define HCZ_WARN(...)          ::HazelCustom::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HCZ_ERROR(...)         ::HazelCustom::Log::GetClientLogger()->error(__VA_ARGS__)
#define HCZ_FATAL(...)         ::HazelCustom::Log::GetClientLogger()->fatal(__VA_ARGS__)

