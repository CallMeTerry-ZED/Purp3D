#ifndef APPLICATION_H
#define APPLICATION_H

#include "purp3d/core/core.h"
#include "purp3d/core/applicationspecification.h"

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

	private:
		ApplicationSpecification m_spec;
		bool m_Running = false;
	};

	// This is to be defined by the CLIENT
	Application* CreateApplication();
}

#endif