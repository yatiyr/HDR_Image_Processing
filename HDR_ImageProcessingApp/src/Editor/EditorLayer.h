#pragma once

#include <HdrIp.h>


#include <Editor/ViewportComponent.h>

namespace HDR_IP
{
	class EditorLayer : public Layer
	{
	public:
		EditorLayer();
		virtual ~EditorLayer() {}
		virtual void OnAttach() override;
		virtual void OnDetach() override;

		virtual void OnUpdate(TimeStep ts) override;
		virtual void OnImGuiRender() override;
		virtual void OnEvent(Event& e) override;

		static EditorLayer* CreateEditor();
		static EditorLayer* GetEditor() { return s_Instance; }

	private:
		bool OnKeyPressed(KeyPressedEvent& e);
		bool OnMouseButtonPressed(MouseButtonPressedEvent& e);
		bool OnWindowResized(WindowResizeEvent& e);
	private:
		void RenderDockspace();
	private:
		ViewportComponent m_ViewportComponent;

		bool m_ViewportFocused = false;
		bool m_ViewportHovered = false;
		glm::vec2 m_ViewportSize = { 0.0f, 0.0f };
		glm::vec2 m_ViewportBounds[2];


		bool m_ExportInProgress = false;
		std::future<void> m_ExportState;
	private:
		static EditorLayer* s_Instance;
		friend class ViewportComponent;
	};
}