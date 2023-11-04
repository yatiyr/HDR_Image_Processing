#include <Precomp.h>
#include <HDR_IP/System/RenderSystem/OpenGL/OpenGLGraphicsContext.h>

#include <GLFW/glfw3.h>
#include <glad/glad.h>


namespace HDR_IP
{
	OpenGLGraphicsContext::OpenGLGraphicsContext(GLFWwindow* windowHandle) : m_WindowHandle(windowHandle) {}

	void OpenGLGraphicsContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		HDR_IP_INFO("Information about OPENGL Renderer and Graphics Card");
		HDR_IP_INFO("  Vendor: {0}", fmt::ptr(glGetString(GL_VENDOR)));
		HDR_IP_INFO("  Renderer: {0}", fmt::ptr(glGetString(GL_RENDERER)));
		HDR_IP_INFO("  Version: {0}", fmt::ptr(glGetString(GL_VERSION)));
	}

	void OpenGLGraphicsContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}
