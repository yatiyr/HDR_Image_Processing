#include <RecoverResponseCurve_HW1/RecoverResponseCurve_HW1.h>
#include <imgui/imgui.h>
#include <implot/implot.h>

#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>


#include <HDR_IP/System/ResourceSystem/ResourceManager.h>


#include <HDR_IP/System/GuiSystem/Font/Font.h>

#include <glad/glad.h>



#include <HDR_IP/System/Utils/PlatformUtils.h>

namespace HDR_IP
{
	RecoverResponseCurve_HW1* RecoverResponseCurve_HW1::s_Instance = nullptr;

	RecoverResponseCurve_HW1* RecoverResponseCurve_HW1::CreateRecoverResponseCurve_HW1()
	{
		s_Instance = new RecoverResponseCurve_HW1();
		return s_Instance;
	}

	RecoverResponseCurve_HW1::RecoverResponseCurve_HW1() : Layer("RecoverResponseCurve_HW1") {}

	void RecoverResponseCurve_HW1::OnAttach()
	{

	}

	void RecoverResponseCurve_HW1::RenderDockspace()
	{
		static bool dockspaceOpen = true;
		static bool opt_fullscreen = true;
		static bool opt_padding = false;
		static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None | ImGuiDockNodeFlags_AutoHideTabBar;

		// We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
		// because it would be confusing to have two docking targets within each others.
		ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
		if (opt_fullscreen)
		{
			const ImGuiViewport* viewport = ImGui::GetMainViewport();
			ImGui::SetNextWindowPos(viewport->WorkPos);
			ImGui::SetNextWindowSize(viewport->WorkSize);
			ImGui::SetNextWindowViewport(viewport->ID);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 1.0f);
			window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
			window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
		}
		else
		{
			dockspace_flags &= ~ImGuiDockNodeFlags_PassthruCentralNode;
		}

		// When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background
		// and handle the pass-thru hole, so we ask Begin() to not render a background.
		if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
			window_flags |= ImGuiWindowFlags_NoBackground;

		// Important: note that we proceed even if Begin() returns false (aka window is collapsed).
		// This is because we want to keep our DockSpace() active. If a DockSpace() is inactive,
		// all active windows docked into it will lose their parent and become undocked.
		// We cannot preserve the docking relationship between an active window and an inactive docking, otherwise
		// any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
		if (!opt_padding)
			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
		ImGui::Begin("##GP_Dockspace", &dockspaceOpen, window_flags);
		if (!opt_padding)
			ImGui::PopStyleVar();

		if (opt_fullscreen)
			ImGui::PopStyleVar(2);

		// Submit the DockSpace
		ImGuiIO& io = ImGui::GetIO();
		ImGuiStyle& style = ImGui::GetStyle();
		float minWinSizeX = style.WindowMinSize.x;

		if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
		{
			ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
			ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
		}

		style.WindowMinSize.x = minWinSizeX;
	}

	void RecoverResponseCurve_HW1::OnDetach() {}

	void RecoverResponseCurve_HW1::OnUpdate(TimeStep ts)
	{

	}


	void RecoverResponseCurve_HW1::OnImGuiRender()
	{
		RenderDockspace();

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2{ 10,10 });
		ImGui::PushStyleVar(ImGuiStyleVar_WindowMinSize, ImVec2{ 1000, 200 });
		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				// Disabling fullscreen would allow the window to be moved to the front of other windows,
				// which we can't undo at the moment without finer window depth/z control.
				// ImGui::MenuItem("Fullscreen", NULL, &opt_fullscreen);
				if (ImGui::MenuItem("New", "Ctrl+N"))
				{
					
				}

				if (ImGui::MenuItem("Open...", "Ctrl+O"))
				{
					
				}

				if (ImGui::MenuItem("Save As...", "Ctrl+Shift+S"))
				{
					
				}

				if (ImGui::MenuItem("Exit")) { Application::Get().Close(); }
				/*if (ImGui::MenuItem("Flag: NoResize", "", (dockspace_flags & ImGuiDockNodeFlags_NoResize) != 0)) { dockspace_flags ^= ImGuiDockNodeFlags_NoResize; } */
				ImGui::EndMenu();
			}

			ImGui::EndMenuBar();
		}

		ImGui::PopStyleVar();
		ImGui::PopStyleVar();


		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(10, 10));
		ImGui::Begin("Properties", nullptr, ImGuiWindowFlags_NoTitleBar);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(5, 5));

		if (ImGui::Button("Open Folder"))
		{
			std::wstring x = FileDialogs::BrowseFolder();
			std::filesystem::path path(x);
			HDR_IP_INFO("Folder {0} has been opened", path.string());
		}

		ImGui::PopStyleVar();
		ImGui::End();
		ImGui::PopStyleVar();


		ImGui::End();

	}

	void RecoverResponseCurve_HW1::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FUNCTION(RecoverResponseCurve_HW1::OnKeyPressed));
		dispatcher.Dispatch<MouseButtonPressedEvent>(BIND_EVENT_FUNCTION(RecoverResponseCurve_HW1::OnMouseButtonPressed));
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FUNCTION(RecoverResponseCurve_HW1::OnWindowResized));
	}

	bool RecoverResponseCurve_HW1::OnMouseButtonPressed(MouseButtonPressedEvent& e)
	{
		return false;
	}

	bool RecoverResponseCurve_HW1::OnWindowResized(WindowResizeEvent& e)
	{
		// MainRender::ResizeViewport(e.GetWidth(), e.GetHeight());
		return false;
	}

	bool RecoverResponseCurve_HW1::OnKeyPressed(KeyPressedEvent& e)
	{
		if (e.GetRepeatCount() > 0)
			return false;

		switch (e.GetKeyCode())
		{
			// Gizmo stuff
			case Key::Q:
	
				break;
			case Key::W:

				break;
			case Key::E:

				break;
			case Key::R:

				break;
		}

		return false;
	}

}