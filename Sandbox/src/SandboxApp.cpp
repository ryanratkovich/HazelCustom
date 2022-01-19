#include <HazelCustom.h>;

class ExampleLayer : public HazelCustom::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		HCZ_INFO("ExampleLayer::Update");
	}

	void OnEvent(HazelCustom::Event& event) override
	{
		HCZ_TRACE("{0}", event);
	}

};

class Sandbox : public HazelCustom::Application
{
public:
    Sandbox()
    {
		PushLayer(new ExampleLayer());
		PushOverlay(new HazelCustom::ImGuiLayer());
    }

    ~Sandbox()
    {

    }
};

HazelCustom::Application* HazelCustom::CreateApplication()
{
    return new Sandbox();
}