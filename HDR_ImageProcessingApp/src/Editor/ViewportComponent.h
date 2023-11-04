#pragma once

#include <HDR_IP/System/EventSystem/MouseEvent.h>
#include <glm/glm.hpp>

namespace HDR_IP
{
	class ViewportComponent
	{
	public:
		ViewportComponent() = default;

		void OnImGuiRender();


		void OnAttach();
		void ResizeFramebuffer();

		bool OnMouseButtonPressed(MouseButtonPressedEvent& e);

		glm::vec2 GetViewportSize()
		{
			return m_ViewportSize;
		}

	private:


		bool m_ViewportFocused = false;
		bool m_ViewportHovered = false;
		glm::vec2 m_ViewportSize = { 1280.0f, 720.0f };
		glm::vec2 m_ViewportBounds[2] = { {0.0f, 0.0f}, {0.0f, 0.0f} };

		friend class EditorLayer;
	};
}