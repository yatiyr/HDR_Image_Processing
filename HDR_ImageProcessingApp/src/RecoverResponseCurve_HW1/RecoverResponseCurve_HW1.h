#pragma once

#include <HdrIp.h>
#include <HDR_IP/System/Image/Image.h>
#include <filesystem>
#include <RecoverResponseCurve_HW1/Image_RRC.h>

namespace HDR_IP
{
	class RecoverResponseCurve_HW1 : public Layer
	{
	public:
		RecoverResponseCurve_HW1();
		virtual ~RecoverResponseCurve_HW1() {}
		virtual void OnAttach() override;
		virtual void OnDetach() override;

		virtual void OnUpdate(TimeStep ts) override;
		virtual void OnImGuiRender() override;
		virtual void OnEvent(Event& e) override;

		static RecoverResponseCurve_HW1* CreateRecoverResponseCurve_HW1();
		static RecoverResponseCurve_HW1* GetRecoverResponseCurve_HW1() { return s_Instance; }


	private:
		bool OnKeyPressed(KeyPressedEvent& e);
		bool OnMouseButtonPressed(MouseButtonPressedEvent& e);
		bool OnWindowResized(WindowResizeEvent& e);
		bool m_ResponseCurvesReady = false;
	// HW RELATED PART
	private:
		void InvalidateImages(std::filesystem::path path);
	private:
		void RenderDockspace();
	private:
		std::vector<Ref<Image>> m_Images;
		Ref<Image> m_SelectedImage;
		int m_RGBMap;
	private:
		static RecoverResponseCurve_HW1* s_Instance;
		friend class ViewportComponent;
	};
}