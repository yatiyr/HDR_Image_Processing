#pragma once

#include <Precomp.h>
#include <HDR_IP/System/CoreSystem/Core.h>
#include <HDR_IP/System/InputSystem/MouseButtonCodes.h>
#include <HDR_IP/System/InputSystem/KeyCodes.h>

namespace HDR_IP
{
	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode keycode);
		static bool IsMouseButtonPressed(MouseButtonCode button);

		static std::pair<float, float> GetMousePos();
		static float GetMouseX();
		static float GetMouseY();
	};
}