#pragma once

#ifdef HCZ_PLATFORM_WINDOWS
	#ifdef HCZ_BUILD_DLL
		#define HAZEL_CUSTOM_API __declspec(dllexport)
	#else
		#define HAZEL_CUSTOM_API __declspec(dllimport)
	#endif
#else
	#error HazelCustom only supports Windows
#endif

#ifdef HCZ_ENABLE_ASSERTS
		#define HCZ_ASSERT(x, ...) { if(!(x)) { HCZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
		#define HCZ_CORE_ASSERT(x, ...) { if(!(x)) { HCZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
		#define HCZ_ASSERT(x, ...)
		#define HCZ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)