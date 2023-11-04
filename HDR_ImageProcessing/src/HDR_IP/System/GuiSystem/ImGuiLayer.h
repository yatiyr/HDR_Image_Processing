#pragma once

#include <Precomp.h>

#include <HDR_IP/System/CoreSystem/Layer.h>
#include <HDR_IP/System/EventSystem/AppEvent.h>
#include <HDR_IP/System/EventSystem/KeyEvent.h>
#include <HDR_IP/System/EventSystem/MouseEvent.h>


namespace HDR_IP
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();


		void BlockEvents(bool block) { m_BlockEvents = block; }
		void* GetFontPtr(const std::string& fontName);

		void SetDarkThemeColors();
		void SetGlobalStyles();
	private:
		void LoadFonts(const std::string& fontName);
		void LoadIconFonts();
		std::unordered_map<std::string, void*> ImGuiFontTable;

		bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};
}