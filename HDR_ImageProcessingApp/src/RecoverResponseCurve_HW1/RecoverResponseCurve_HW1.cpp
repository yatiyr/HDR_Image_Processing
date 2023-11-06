#include <RecoverResponseCurve_HW1/RecoverResponseCurve_HW1.h>
#include <imgui/imgui.h>
#include <implot/implot.h>

#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>


#include <HDR_IP/System/ResourceSystem/ResourceManager.h>


#include <HDR_IP/System/GuiSystem/Font/Font.h>

#include <glad/glad.h>

#include <set>

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

	void RecoverResponseCurve_HW1::InvalidateImages(std::filesystem::path path)
	{

		m_Images.clear();
		if (m_SelectedImage)
			m_SelectedImage.reset();

		try
		{
			int count = 0;

			for (const auto& entry : std::filesystem::directory_iterator(path))
			{
				if (entry.is_regular_file() && (
					entry.path().extension() == ".png" ||
					entry.path().extension() == ".jpeg" ||
					entry.path().extension() == ".jpg" ||
					entry.path().extension() == ".JPG" ||
					entry.path().extension() == ".bmp" ||
					entry.path().extension() == ".tga"))
				{
					Ref<Image> im = Image::CreateImage(entry.path().string().c_str());
					m_Images.push_back(im);
					count++;
				}
			}

			HDR_IP_INFO("There are {0} image files in this directory.", count);
		}
		catch (const std::exception&)
		{
			HDR_IP_ERROR("An error occured while loading images");
		}
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

		if (m_Images.size() > 0)
		{
			ImGui::Text("Images in the selected Folder");

			for (auto& image : m_Images)
			{
				ImGui::Text("Image Name: %s", image->GetName().c_str());
				float imageAspectRatio = (float)image->GetWidth() / (float)image->GetHeight();

				if (ImGui::ImageButton((void*)(intptr_t)image->GetOpenGLID(), ImVec2(350 / imageAspectRatio, 350 / imageAspectRatio), ImVec2{ 0, 1 }, ImVec2{ 1, 0 }))
				{
					m_SelectedImage = image;
				}
			}
		}

		if (ImGui::Button("Select Folder"))
		{
			std::wstring x = FileDialogs::BrowseFolder();
			std::filesystem::path path(x);
			HDR_IP_INFO("Folder {0} has been opened", path.string());
			InvalidateImages(path);
		}

		if (m_Images.size() > 0)
		{
			if (ImGui::Button("Recover Response Curve"))
			{
				Image_RRC::RecoverResponseCurve(m_Images);
				m_ResponseCurvesReady = true;
			}
		}

		ImGui::PopStyleVar();
		ImGui::End();
		ImGui::PopStyleVar();

		// -------------- SELECTED IMAGE ------------------------- //
		if (m_SelectedImage)
		{
			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(10, 10));
			ImGui::Begin("SelectedImage", nullptr, ImGuiWindowFlags_NoTitleBar);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(5, 5));

			float imageAspectRatio = (float)m_SelectedImage->GetWidth() / (float)m_SelectedImage->GetHeight();
			ImVec2 panelSize = ImGui::GetContentRegionAvail();

			int minSize = std::min(panelSize.x, panelSize.y);

			ImGui::Image((void*)(intptr_t)m_SelectedImage->GetOpenGLID(), ImVec2(std::min(minSize * imageAspectRatio, panelSize.x), std::min(minSize * imageAspectRatio, panelSize.y)), ImVec2{ 0, 1 }, ImVec2{ 1, 0 });


			ImGui::PopStyleVar();
			ImGui::End();
			ImGui::PopStyleVar();
		}
		// -------------- SELECTED IMAGE ------------------------- //

		// ---------------- RESPONSE CURVE ----------------- //
		if (m_ResponseCurvesReady)
		{
			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(10, 10));
			ImGui::Begin("Response Curve", nullptr, ImGuiWindowFlags_NoTitleBar);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(5, 5));

			std::vector<float> rCR = Image_RRC::GetResponseCurveR();
			std::vector<float> rCG = Image_RRC::GetResponseCurveG();
			std::vector<float> rCB = Image_RRC::GetResponseCurveB();
			std::vector<float> pixValueF = Image_RRC::GetPixelValueFunc();


			if (ImPlot::BeginPlot("Response Curve", ImVec2(-1, 0))) {
				ImPlot::SetupAxisScale(ImAxis_X1, ImPlotScale_Linear);
				ImPlot::SetupAxesLimits(-3.0, 1.5, 0, 256);
				ImPlot::PlotLine("Red", rCR.data(), pixValueF.data(), rCR.size());
				ImPlot::PlotLine("Green", rCG.data(), pixValueF.data(), rCG.size());
				ImPlot::PlotLine("Blue", rCB.data(), pixValueF.data(), rCB.size());
				ImPlot::EndPlot();
			}

			ImGui::PopStyleVar();
			ImGui::End();
			ImGui::PopStyleVar();
		}
		// ---------------- RESPONSE CURVE ----------------- //

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