#ifndef APPLICATION_H
#define APPLICATION_H

#include "purp3d/core/core.h"

namespace Purp3D
{
	class PURP_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// This is to be defined by the CLIENT
	Application* CreateApplication();
}

#endif