#ifndef SCRIPT_ENGINE_H
#define SCRIPT_ENGINE_H

#include "purp3d/core/core.h"
#include "purp3d/core/events/event.h"

namespace Purp3D
{
	class PURP_API ScriptEngine
	{
	public:
		static void Init();
		static void Shutdown();

		static void OnStart();
		static void OnUpdate(float dt);
		static void OnEvent(Event& e);
	};
}


#endif