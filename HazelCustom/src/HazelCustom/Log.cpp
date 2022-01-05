#include "hczpch.h"
#include "Log.h"

namespace HazelCustom
{

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::level::level_enum level = spdlog::level::trace;

		// T = timestamp n = logger v = message
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("HAZELCUSTOM");
		s_CoreLogger->set_level(level);

		s_ClientLogger = spdlog::stdout_color_mt("App");
		s_ClientLogger->set_level(level);
	}
}


