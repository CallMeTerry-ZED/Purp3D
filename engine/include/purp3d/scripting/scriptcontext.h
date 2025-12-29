#ifndef SCRIPT_CONTEXT_H
#define SCRIPT_CONTEXT_H

#include "purp3d/core/core.h"
#include <string>

namespace Purp3D
{
	// TODO: Move this to events folder
	// into its own file scriptevent.h
	struct PURP_API ScriptEvent
	{
		int Type;
		bool Handled = false;
	};

	class PURP_API ScriptContext
	{
	public:
		static void OnStart();
		static void OnUpdate(float dt);
		static void OnEvent(ScriptEvent& event);
	};
}

#endif