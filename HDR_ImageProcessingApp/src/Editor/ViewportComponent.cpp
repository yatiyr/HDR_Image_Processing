#include <Precomp.h>

#include <Editor/ViewportComponent.h>
#include <HDR_IP/System/CoreSystem/Application.h>
#include <HDR_IP/System/InputSystem/MouseButtonCodes.h>
#include <imgui/imgui.h>

#include <Editor/EditorLayer.h>

#include <glm/gtc/type_ptr.hpp>
#include <Math/Math.h>


namespace HDR_IP
{
	void ViewportComponent::OnAttach() {}

	void ViewportComponent::ResizeFramebuffer()
	{
		EditorLayer* elInstance = EditorLayer::GetEditor();

	}

	bool ViewportComponent::OnMouseButtonPressed(MouseButtonPressedEvent& e)
	{
		if (e.GetMouseButton() == (int)MouseButton::ButtonLeft)
		{


		}
		return false;
	}

	void ViewportComponent::OnImGuiRender()
	{
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2{ 0, 0 });
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 1);

		ImGui::Begin("##Viewport");

		auto viewportMinRegion = ImGui::GetWindowContentRegionMin();
		auto viewportMaxRegion = ImGui::GetWindowContentRegionMax();
		auto viewportOffset    = ImGui::GetWindowPos();

		m_ViewportBounds[0] = { viewportMinRegion.x + viewportOffset.x,
								viewportMinRegion.y + viewportOffset.y };

		m_ViewportBounds[1] = { viewportMaxRegion.x + viewportOffset.x,
								viewportMaxRegion.y + viewportOffset.y };

		m_ViewportFocused = ImGui::IsWindowFocused();
		m_ViewportHovered = ImGui::IsWindowHovered();

		Application::Get().GetImGuiLayer()->BlockEvents(!m_ViewportFocused && !m_ViewportHovered);

		ImVec2 viewportPanelSize = ImGui::GetContentRegionAvail();
		if (m_ViewportSize != *((glm::vec2*)&viewportPanelSize) && viewportPanelSize.x > 0 && viewportPanelSize.y > 0)
		{
			m_ViewportSize = { (uint32_t)viewportPanelSize.x, (uint32_t)viewportPanelSize.y };
		}

		//uint32_t textureID = m_Framebuffer->GetColorAttachmentRendererID();
		//ImGui::Image((void*)textureID, ImVec2(m_ViewportSize.x, m_ViewportSize.y), ImVec2{ 0, 1 }, ImVec2{ 1, 0 });


		ImGui::End();
		ImGui::PopStyleVar(2);
	}

}