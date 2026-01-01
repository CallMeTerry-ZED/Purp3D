// Copyright (c) 2025-2026 ZED Interactive

#ifndef LUA_VM_H
#define LUA_VM_H

#include "purp3d/core/core.h"
#include <sol/sol.hpp>
#include "purp3d/scripting/scriptcontext.h"

namespace Purp3D
{
	class LuaVM
	{
	public:
		static void Init();
		static void Shutdown();

		static void CallStart();
		static void CallUpdate(float dt);
		static void CallEvent(ScriptEvent& event);

		static sol::state& GetState();

	private:
		static sol::state s_Lua;
	};
}

#endif