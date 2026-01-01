// Copyright (c) 2025-2026 ZED Interactive

#ifndef SCRIPT_CONTEXT_H
#define SCRIPT_CONTEXT_H

#include "purp3d/core/core.h"
#include "purp3d/core/events/scriptevents.h"
#include <string>

namespace Purp3D
{
	class PURP_API ScriptContext
	{
	public:
		static void OnStart();
		static void OnUpdate(float dt);
		static void OnEvent(ScriptEvent& event);
	};
}

#endif