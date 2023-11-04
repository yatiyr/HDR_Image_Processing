#pragma once

#include <HDR_IP/System/CoreSystem/Core.h>
#include <HDR_IP/System/EventSystem/Event.h>
#include <HDR_IP/System/CoreSystem/TimeStep.h>

namespace HDR_IP
{
	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(TimeStep time) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};
}