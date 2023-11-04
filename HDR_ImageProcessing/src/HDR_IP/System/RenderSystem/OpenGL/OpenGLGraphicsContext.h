#pragma once

#include <HDR_IP/System/RenderSystem/GraphicsContext.h>

struct GLFWwindow;

namespace HDR_IP
{
	class OpenGLGraphicsContext : public GraphicsContext
	{
	public:
		OpenGLGraphicsContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};
}