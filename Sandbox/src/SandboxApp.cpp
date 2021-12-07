#include <HazelCustom.h>;

class Sandbox : public HazelCustom::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

HazelCustom::Application* HazelCustom::CreateApplication()
{
	return new Sandbox();
}