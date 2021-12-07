#pragma once

#ifdef HZC_PLATFORM_WINDOWS
	#ifdef HZC_BUILD_DLL
		#define HAZELCUSTOM_API __declspec(dllexport)
	#else
		#define HAZELCUSTOM_API __declspec(dllimport)
	#endif
#else
	#error HazelCustom only supports WIndows
#endif