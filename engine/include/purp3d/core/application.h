#ifndef APPLICATION_H
#define APPLICATION_H

#include "purp3d/core/core.h"
#include "purp3d/core/applicationspecification.h"
#include "purp3d/core/window.h"
#include "purp3d/core/events/eventqueue.h"
#include <glm/glm.hpp>
#include <memory>
#include <vector>


namespace Purp3D
{
	class PURP_API Application
	{
	public:
		Application(const ApplicationSpecification& specification = ApplicationSpecification());
		virtual ~Application();

		void Run();
		void Stop();

		static Application& Get();
		static float GetTime();
		glm::vec2 GetFramebufferSize() const;
		std::shared_ptr<Window> GetWindow() const { return m_Window; }

	private:
		void ProcessEvents();

		static Application* s_Instance;
		ApplicationSpecification m_spec;
		std::shared_ptr<Window> m_Window;
		EventQueue m_EventQueue;
		bool m_Running = false;
	};

	// This is to be defined by the CLIENT
	Application* CreateApplication();
}

#endif