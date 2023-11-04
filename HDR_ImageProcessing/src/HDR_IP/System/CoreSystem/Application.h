#pragma once

#include <HDR_IP/System/WindowSystem/Window.h>
#include <HDR_IP/System/CoreSystem/Core.h>
#include <HDR_IP/System/CoreSystem/LayerStack.h>
#include <HDR_IP/System/EventSystem/Event.h>
#include <HDR_IP/System/EventSystem/AppEvent.h>

#include <HDR_IP/System/CoreSystem/TimeStep.h>
#include <HDR_IP/System/GuiSystem/ImGuiLayer.h>

namespace HDR_IP
{

	class Application
	{
	public:
		Application(const std::string& name = "App");
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);
		

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		Window& GetWindow() { return *m_Window; }

		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

		static Application& Get() { return *s_Instance; }

		float GetDpiScale() { return m_DpiScale; }

	private:
		bool OnWindowClosed(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

	private:
		Ref<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_isRunning = true;
		bool m_Minimized = false;

		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
		float m_DpiScale = 0.0f;
	private:
		static Application* s_Instance;
	};

	// Client will define this
	Application* CreateApplication();
}