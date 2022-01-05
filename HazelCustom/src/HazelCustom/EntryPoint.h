#pragma once

#ifdef HCZ_PLATFORM_WINDOWS

extern HazelCustom::Application* HazelCustom::CreateApplication();
	
int main(int argc, char** argv) 
{
	HazelCustom::Log::Init();
	HCZ_CORE_WARN("Initialized Log!");
	int a = 5;
	HCZ_INFO("Hello Var={0}", a);

	printf("HazelCustom Engine\n");
	auto app = HazelCustom::CreateApplication();
	app->Run();
	delete app;
}

#endif