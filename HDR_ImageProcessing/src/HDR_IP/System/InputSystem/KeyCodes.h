#pragma once

#include <Precomp.h>

namespace HDR_IP
{

	typedef enum class KeyCode : uint16_t
	{
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

#define HDR_IP_KEY_SPACE           ::HDR_IP::Key::Space
#define HDR_IP_KEY_APOSTROPHE      ::HDR_IP::Key::Apostrophe    /* ' */
#define HDR_IP_KEY_COMMA           ::HDR_IP::Key::Comma         /* , */
#define HDR_IP_KEY_MINUS           ::HDR_IP::Key::Minus         /* - */
#define HDR_IP_KEY_PERIOD          ::HDR_IP::Key::Period        /* . */
#define HDR_IP_KEY_SLASH           ::HDR_IP::Key::Slash         /* / */
#define HDR_IP_KEY_0               ::HDR_IP::Key::D0
#define HDR_IP_KEY_1               ::HDR_IP::Key::D1
#define HDR_IP_KEY_2               ::HDR_IP::Key::D2
#define HDR_IP_KEY_3               ::HDR_IP::Key::D3
#define HDR_IP_KEY_4               ::HDR_IP::Key::D4
#define HDR_IP_KEY_5               ::HDR_IP::Key::D5
#define HDR_IP_KEY_6               ::HDR_IP::Key::D6
#define HDR_IP_KEY_7               ::HDR_IP::Key::D7
#define HDR_IP_KEY_8               ::HDR_IP::Key::D8
#define HDR_IP_KEY_9               ::HDR_IP::Key::D9
#define HDR_IP_KEY_SEMICOLON       ::HDR_IP::Key::Semicolon     /* ; */
#define HDR_IP_KEY_EQUAL           ::HDR_IP::Key::Equal         /* = */
#define HDR_IP_KEY_A               ::HDR_IP::Key::A
#define HDR_IP_KEY_B               ::HDR_IP::Key::B
#define HDR_IP_KEY_C               ::HDR_IP::Key::C
#define HDR_IP_KEY_D               ::HDR_IP::Key::D
#define HDR_IP_KEY_E               ::HDR_IP::Key::E
#define HDR_IP_KEY_F               ::HDR_IP::Key::F
#define HDR_IP_KEY_G               ::HDR_IP::Key::G
#define HDR_IP_KEY_H               ::HDR_IP::Key::H
#define HDR_IP_KEY_I               ::HDR_IP::Key::I
#define HDR_IP_KEY_J               ::HDR_IP::Key::J
#define HDR_IP_KEY_K               ::HDR_IP::Key::K
#define HDR_IP_KEY_L               ::HDR_IP::Key::L
#define HDR_IP_KEY_M               ::HDR_IP::Key::M
#define HDR_IP_KEY_N               ::HDR_IP::Key::N
#define HDR_IP_KEY_O               ::HDR_IP::Key::O
#define HDR_IP_KEY_P               ::HDR_IP::Key::P
#define HDR_IP_KEY_Q               ::HDR_IP::Key::Q
#define HDR_IP_KEY_R               ::HDR_IP::Key::R
#define HDR_IP_KEY_S               ::HDR_IP::Key::S
#define HDR_IP_KEY_T               ::HDR_IP::Key::T
#define HDR_IP_KEY_U               ::HDR_IP::Key::U
#define HDR_IP_KEY_V               ::HDR_IP::Key::V
#define HDR_IP_KEY_W               ::HDR_IP::Key::W
#define HDR_IP_KEY_X               ::HDR_IP::Key::X
#define HDR_IP_KEY_Y               ::HDR_IP::Key::Y
#define HDR_IP_KEY_Z               ::HDR_IP::Key::Z
#define HDR_IP_KEY_LEFT_BRACKET    ::HDR_IP::Key::LeftBracket   /* [ */
#define HDR_IP_KEY_BACKSLASH       ::HDR_IP::Key::Backslash     /* \ */
#define HDR_IP_KEY_RIGHT_BRACKET   ::HDR_IP::Key::RightBracket  /* ] */
#define HDR_IP_KEY_GRAVE_ACCENT    ::HDR_IP::Key::GraveAccent   /* ` */
#define HDR_IP_KEY_WORLD_1         ::HDR_IP::Key::World1        /* non-US #1 */
#define HDR_IP_KEY_WORLD_2         ::HDR_IP::Key::World2        /* non-US #2 */

/* Function keys */
#define HDR_IP_KEY_ESCAPE          ::HDR_IP::Key::Escape
#define HDR_IP_KEY_ENTER           ::HDR_IP::Key::Enter
#define HDR_IP_KEY_TAB             ::HDR_IP::Key::Tab
#define HDR_IP_KEY_BACKSPACE       ::HDR_IP::Key::Backspace
#define HDR_IP_KEY_INSERT          ::HDR_IP::Key::Insert
#define HDR_IP_KEY_DELETE          ::HDR_IP::Key::Delete
#define HDR_IP_KEY_RIGHT           ::HDR_IP::Key::Right
#define HDR_IP_KEY_LEFT            ::HDR_IP::Key::Left
#define HDR_IP_KEY_DOWN            ::HDR_IP::Key::Down
#define HDR_IP_KEY_UP              ::HDR_IP::Key::Up
#define HDR_IP_KEY_PAGE_UP         ::HDR_IP::Key::PageUp
#define HDR_IP_KEY_PAGE_DOWN       ::HDR_IP::Key::PageDown
#define HDR_IP_KEY_HOME            ::HDR_IP::Key::Home
#define HDR_IP_KEY_END             ::HDR_IP::Key::End
#define HDR_IP_KEY_CAPS_LOCK       ::HDR_IP::Key::CapsLock
#define HDR_IP_KEY_SCROLL_LOCK     ::HDR_IP::Key::ScrollLock
#define HDR_IP_KEY_NUM_LOCK        ::HDR_IP::Key::NumLock
#define HDR_IP_KEY_PRINT_SCREEN    ::HDR_IP::Key::PrintScreen
#define HDR_IP_KEY_PAUSE           ::HDR_IP::Key::Pause
#define HDR_IP_KEY_F1              ::HDR_IP::Key::F1
#define HDR_IP_KEY_F2              ::HDR_IP::Key::F2
#define HDR_IP_KEY_F3              ::HDR_IP::Key::F3
#define HDR_IP_KEY_F4              ::HDR_IP::Key::F4
#define HDR_IP_KEY_F5              ::HDR_IP::Key::F5
#define HDR_IP_KEY_F6              ::HDR_IP::Key::F6
#define HDR_IP_KEY_F7              ::HDR_IP::Key::F7
#define HDR_IP_KEY_F8              ::HDR_IP::Key::F8
#define HDR_IP_KEY_F9              ::HDR_IP::Key::F9
#define HDR_IP_KEY_F10             ::HDR_IP::Key::F10
#define HDR_IP_KEY_F11             ::HDR_IP::Key::F11
#define HDR_IP_KEY_F12             ::HDR_IP::Key::F12
#define HDR_IP_KEY_F13             ::HDR_IP::Key::F13
#define HDR_IP_KEY_F14             ::HDR_IP::Key::F14
#define HDR_IP_KEY_F15             ::HDR_IP::Key::F15
#define HDR_IP_KEY_F16             ::HDR_IP::Key::F16
#define HDR_IP_KEY_F17             ::HDR_IP::Key::F17
#define HDR_IP_KEY_F18             ::HDR_IP::Key::F18
#define HDR_IP_KEY_F19             ::HDR_IP::Key::F19
#define HDR_IP_KEY_F20             ::HDR_IP::Key::F20
#define HDR_IP_KEY_F21             ::HDR_IP::Key::F21
#define HDR_IP_KEY_F22             ::HDR_IP::Key::F22
#define HDR_IP_KEY_F23             ::HDR_IP::Key::F23
#define HDR_IP_KEY_F24             ::HDR_IP::Key::F24
#define HDR_IP_KEY_F25             ::HDR_IP::Key::F25

/* Keypad */
#define HDR_IP_KEY_KP_0            ::HDR_IP::Key::KP0
#define HDR_IP_KEY_KP_1            ::HDR_IP::Key::KP1
#define HDR_IP_KEY_KP_2            ::HDR_IP::Key::KP2
#define HDR_IP_KEY_KP_3            ::HDR_IP::Key::KP3
#define HDR_IP_KEY_KP_4            ::HDR_IP::Key::KP4
#define HDR_IP_KEY_KP_5            ::HDR_IP::Key::KP5
#define HDR_IP_KEY_KP_6            ::HDR_IP::Key::KP6
#define HDR_IP_KEY_KP_7            ::HDR_IP::Key::KP7
#define HDR_IP_KEY_KP_8            ::HDR_IP::Key::KP8
#define HDR_IP_KEY_KP_9            ::HDR_IP::Key::KP9
#define HDR_IP_KEY_KP_DECIMAL      ::HDR_IP::Key::KPDecimal
#define HDR_IP_KEY_KP_DIVIDE       ::HDR_IP::Key::KPDivide
#define HDR_IP_KEY_KP_MULTIPLY     ::HDR_IP::Key::KPMultiply
#define HDR_IP_KEY_KP_SUBTRACT     ::HDR_IP::Key::KPSubtract
#define HDR_IP_KEY_KP_ADD          ::HDR_IP::Key::KPAdd
#define HDR_IP_KEY_KP_ENTER        ::HDR_IP::Key::KPEnter
#define HDR_IP_KEY_KP_EQUAL        ::HDR_IP::Key::KPEqual

#define HDR_IP_KEY_LEFT_SHIFT      ::HDR_IP::Key::LeftShift
#define HDR_IP_KEY_LEFT_CONTROL    ::HDR_IP::Key::LeftControl
#define HDR_IP_KEY_LEFT_ALT        ::HDR_IP::Key::LeftAlt
#define HDR_IP_KEY_LEFT_SUPER      ::HDR_IP::Key::LeftSuper
#define HDR_IP_KEY_RIGHT_SHIFT     ::HDR_IP::Key::RightShift
#define HDR_IP_KEY_RIGHT_CONTROL   ::HDR_IP::Key::RightControl
#define HDR_IP_KEY_RIGHT_ALT       ::HDR_IP::Key::RightAlt
#define HDR_IP_KEY_RIGHT_SUPER     ::HDR_IP::Key::RightSuper
#define HDR_IP_KEY_MENU            ::HDR_IP::Key::Menu

#define HDR_IP_KEY_LAST               HDR_IP_KEY_MENU