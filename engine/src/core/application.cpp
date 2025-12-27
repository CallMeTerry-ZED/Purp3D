#include "purp3d/core/application.h"
#include <cstdio>
#include <cassert>
#include <iostream>

namespace Purp3D
{
	static Application* s_Application = nullptr;

	static void GLFWErrorCallback(int error, const char* description)
	{
		std::cerr << "[GLFW Error]: " << description << std::endl;
	}

	Application::Application(const ApplicationSpecification& specification) : m_spec(specification)
	{
		s_Application = this;

		glfwSetErrorCallback(GLFWErrorCallback);
		glfwInit();

		// Sets the window title to be the name of the app
		// If one is set and no window title has been set
		if (m_spec.WindowSpec.Title == nullptr)
		{
			m_spec.WindowSpec.Title = m_spec.Name;
		}

		m_Window = std::make_shared<Window>(m_spec.WindowSpec);
		m_Window->Create();
	}

	Application::~Application()
	{
		m_Window->Destroy();

		glfwTerminate();

		s_Application = nullptr;
	}

	void Application::Run()
	{
		m_Running = true;

		while (m_Running)
		{
			glfwPollEvents();

			if (m_Window->ShouldClose())
			{
				Stop();
				break;
			}
		}
		m_Window->Update();
	}

	void Application::Stop()
	{
		m_Running = false;
	}

	Application& Application::Get()
	{
		assert(s_Application);
		return *s_Application;
	}

	float Application::GetTime()
	{
		return (float)glfwGetTime();
	}
}
