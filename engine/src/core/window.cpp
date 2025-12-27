#include "purp3d/core/window.h"
#include <cassert>
#include <iostream>

namespace Purp3D
{
	Window::Window(const WindowSpecification& specification) : m_spec(specification)
	{

	}

	Window::~Window()
	{
		Destroy();
	}

	void Window::Create()
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

		m_Handle = glfwCreateWindow(m_spec.Width, m_spec.Height, m_spec.Title, nullptr, nullptr);
		if (!m_Handle)
		{
			std::cerr << "Failed to create GLFW window!\n";
			assert(false);
		}
		glfwMakeContextCurrent(m_Handle);

		glfwSwapInterval(m_spec.VSync ? 1 : 0);

		glfwSetWindowUserPointer(m_Handle, this);

		glfwSetWindowCloseCallback(m_Handle, [](GLFWwindow* handle)
		{
			Window& window = *((Window*)glfwGetWindowUserPointer(handle));
		});

		glfwSetWindowSizeCallback(m_Handle, [](GLFWwindow* handle, int width, int height)
		{
			Window& window = *((Window*)glfwGetWindowUserPointer(handle));
		});

		glfwSetKeyCallback(m_Handle, [](GLFWwindow* handle, int key, int scancode, int action, int mods)
		{
			Window& window = *((Window*)glfwGetWindowUserPointer(handle));
		});

		glfwSetMouseButtonCallback(m_Handle, [](GLFWwindow* handle, int button, int action, int mods)
		{
			Window& window = *((Window*)glfwGetWindowUserPointer(handle));
		});

		glfwSetScrollCallback(m_Handle, [](GLFWwindow* handle, double xOffset, double yOffset)
		{
			Window& window = *((Window*)glfwGetWindowUserPointer(handle));
		});

		glfwSetCursorPosCallback(m_Handle, [](GLFWwindow* handle, double x, double y)
		{
			Window& window = *((Window*)glfwGetWindowUserPointer(handle));
		});
	}

	void Window::Destroy()
	{
		if (m_Handle)
			glfwDestroyWindow(m_Handle);

		m_Handle = nullptr;
	}

	void Window::Update()
	{
		glfwSwapBuffers(m_Handle);
	}

	bool Window::ShouldClose() const
	{
		return glfwWindowShouldClose(m_Handle) != 0;
	}
}