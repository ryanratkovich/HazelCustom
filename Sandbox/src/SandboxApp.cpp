#include <HazelCustom.h>

#include "imgui/imgui.h"

class ExampleLayer : public HazelCustom::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (HazelCustom::Input::IsKeyPressed(HCZ_KEY_TAB))
		{
			HCZ_TRACE("Tab Key is pressed!");
		}
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(HazelCustom::Event& event) override
	{
		if (event.GetEventType() == HazelCustom::EventType::KeyPressed)
		{
			HazelCustom::KeyPressedEvent& e = (HazelCustom::KeyPressedEvent&)event;
			if (e.GetKeyCode() == HCZ_KEY_TAB)
				HCZ_TRACE("Tab key is pressed (event)!");
			HCZ_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

};

class Sandbox : public HazelCustom::Application
{
public:
    Sandbox()
    {
		PushLayer(new ExampleLayer());
    }

    ~Sandbox()
    {

    }
};

HazelCustom::Application* HazelCustom::CreateApplication()
{
    return new Sandbox();
}