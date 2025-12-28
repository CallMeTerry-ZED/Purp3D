#include "purp3d/core/window.h"
#include "purp3d/core/events/windowevents.h"
#include "purp3d/core/events/keyevents.h"
#include "purp3d/core/events/mouseevents.h"
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
		gladLoadGL(glfwGetProcAddress);

		glfwSwapInterval(m_spec.VSync ? 1 : 0);

		glfwSetWindowUserPointer(m_Handle, this);

		glfwSetWindowCloseCallback(m_Handle, [](GLFWwindow* handle)
		{
			auto& window = *(Window*)glfwGetWindowUserPointer(handle);
			window.m_EventCallback(std::make_unique<WindowCloseEvent>());
		});

		glfwSetWindowSizeCallback(m_Handle, [](GLFWwindow* handle, int w, int h)
		{
			auto& window = *(Window*)glfwGetWindowUserPointer(handle);
			window.m_EventCallback(std::make_unique<WindowResizeEvent>(w, h));
		});

		glfwSetKeyCallback(m_Handle, [](GLFWwindow* handle, int key, int, int action, int)
		{
			auto& window = *(Window*)glfwGetWindowUserPointer(handle);

			if (action == GLFW_PRESS)
			{
				window.m_EventCallback(std::make_unique<KeyPressedEvent>(key, false));
			}
			else if (action == GLFW_REPEAT)
			{
				window.m_EventCallback(std::make_unique<KeyPressedEvent>(key, true));
			}
			else if (action == GLFW_RELEASE)
			{
				window.m_EventCallback(std::make_unique<KeyReleasedEvent>(key));
			}
		});

		glfwSetCursorPosCallback(m_Handle, [](GLFWwindow* handle, double x, double y)
		{
			auto& window = *(Window*)glfwGetWindowUserPointer(handle);
			window.m_EventCallback(std::make_unique<MouseMovedEvent>((float)x, (float)y));
		});

		glfwSetScrollCallback(m_Handle, [](GLFWwindow* handle, double x, double y)
		{
			auto& window = *(Window*)glfwGetWindowUserPointer(handle);
			window.m_EventCallback(std::make_unique<MouseScrolledEvent>((float)x, (float)y));
		});

		glfwSetMouseButtonCallback(m_Handle, [](GLFWwindow* handle, int button, int action, int)
		{
			auto& window = *(Window*)glfwGetWindowUserPointer(handle);

			if (action == GLFW_PRESS)
			{
				window.m_EventCallback(std::make_unique<MouseButtonPressedEvent>(button));
			}
			else if (action == GLFW_RELEASE)
			{
				window.m_EventCallback(std::make_unique<MouseButtonReleasedEvent>(button));
			}
		});
	}

	void Window::Destroy()
	{
		if (m_Handle)
		{
			glfwDestroyWindow(m_Handle);
		}

		m_Handle = nullptr;
	}

	void Window::Update()
	{
		glfwSwapBuffers(m_Handle);
	}

	glm::vec2 Window::GetFramebufferSize() const
	{
		int width, height;
		glfwGetFramebufferSize(m_Handle, &width, &height);
		return { width, height };
	}

	glm::vec2 Window::GetMousePos() const
	{
		double x, y;
		glfwGetCursorPos(m_Handle, &x, &y);
		return { static_cast<float>(x), static_cast<float>(y) };
	}

	bool Window::ShouldClose() const
	{
		return glfwWindowShouldClose(m_Handle) != 0;
	}
}