#include "purp3d/core/application.h"
#include <glm/glm.hpp>
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

		m_Window->SetEventCallback(
			[this](std::unique_ptr<Event> event)
			{
				m_EventQueue.Push(std::move(event));
			}
		);

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

		float lastTime = GetTime();

		while (m_Running)
		{
			glfwPollEvents();

			ProcessEvents();

			if (m_Window->ShouldClose())
			{
				Stop();
				break;
			}

			float currentTime = GetTime();
			float timestep = glm::clamp(currentTime - lastTime, 0.001f, 0.1f);
			lastTime = currentTime;

			m_Window->Update();
		}
	}

	void Application::Stop()
	{
		m_Running = false;
	}

	void Application::ProcessEvents()
	{
		while (!m_EventQueue.Empty())
		{
			auto event = m_EventQueue.Pop();
		}
	}

	glm::vec2 Application::GetFramebufferSize() const
	{
		return m_Window->GetFramebufferSize();
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
