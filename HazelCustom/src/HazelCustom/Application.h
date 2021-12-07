#pragma once

#include "Core.h";

namespace HazelCustom
{
	class HAZELCUSTOM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();

} 

