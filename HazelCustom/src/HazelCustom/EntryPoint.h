#pragma once

#ifdef HZC_PLATFORM_WINDOWS

extern HazelCustom::Application* HazelCustom::CreateApplication();
	
int main(int argc, char** argv) 
{
	printf("HazelCustom Engine\n");
	auto app = HazelCustom::CreateApplication();
	app->Run();
	delete app;
}

#endif