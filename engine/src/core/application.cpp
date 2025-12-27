#include "purp3d/core/application.h"
#include <cstdio>
#include <cassert>

namespace Purp3D
{
	static Application* s_Application = nullptr;

	Application::Application(const ApplicationSpecification& specification) : m_spec(specification)
	{
		s_Application = this;

	}

	Application::~Application()
	{
		s_Application = nullptr;
		Stop();
	}

	void Application::Run()
	{
		m_Running = true;

		while (m_Running)
		{

		}
		std::printf("Purp3D Application running\n");
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
}
