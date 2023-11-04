#pragma once

#include <Precomp.h>

namespace HDR_IP
{
	typedef enum class MouseButtonCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} MouseButton;

	inline std::ostream& operator<<(std::ostream& os, MouseButtonCode mouseButtonCode)
	{
		os << static_cast<int32_t>(mouseButtonCode);
		return os;
	}
}

/* Mouse button code taken from glfw */
#define HDR_IP_MOUSE_BUTTON_0      ::HDR_IP::Mouse::Button0
#define HDR_IP_MOUSE_BUTTON_1      ::HDR_IP::Mouse::Button1
#define HDR_IP_MOUSE_BUTTON_2      ::HDR_IP::Mouse::Button2
#define HDR_IP_MOUSE_BUTTON_3      ::HDR_IP::Mouse::Button3
#define HDR_IP_MOUSE_BUTTON_4      ::HDR_IP::Mouse::Button4
#define HDR_IP_MOUSE_BUTTON_5      ::HDR_IP::Mouse::Button5
#define HDR_IP_MOUSE_BUTTON_6      ::HDR_IP::Mouse::Button6
#define HDR_IP_MOUSE_BUTTON_7      ::HDR_IP::Mouse::Button7
#define HDR_IP_MOUSE_BUTTON_LAST   ::HDR_IP::Mouse::ButtonLast
#define HDR_IP_MOUSE_BUTTON_LEFT   ::HDR_IP::Mouse::ButtonLeft
#define HDR_IP_MOUSE_BUTTON_RIGHT  ::HDR_IP::Mouse::ButtonRight
#define HDR_IP_MOUSE_BUTTON_MIDDLE ::HDR_IP::Mouse::ButtonMiddle