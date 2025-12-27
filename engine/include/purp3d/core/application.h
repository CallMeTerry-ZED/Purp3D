#ifndef APPLICATION_H
#define APPLICATION_H

#include "purp3d/core/core.h"
#include "purp3d/core/applicationspecification.h"
#include "purp3d/core/window.h"
#include <memory>

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
		std::shared_ptr<Window> GetWindow() const { return m_Window; }

	private:
		ApplicationSpecification m_spec;
		std::shared_ptr<Window> m_Window;
		bool m_Running = false;
	};

	// This is to be defined by the CLIENT
	Application* CreateApplication();
}

#endif