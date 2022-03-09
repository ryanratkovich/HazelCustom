#pragma once

#include "Core.h"

#include "Window.h"
#include "HazelCustom/LayerStack.h"
#include "HazelCustom/Events/Event.h"
#include "HazelCustom/Events/ApplicationEvent.h"

#include "HazelCustom/ImGui/ImGuiLayer.h"

namespace HazelCustom
{
	class HAZEL_CUSTOM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		// Singleton to our application instance
		static Application* s_Instance;
	};

	// To be defined in client
	Application* CreateApplication();

} 

