// Copyright (c) 2025-2026 ZED Interactive

#include "purp3d/scripting/lua/luabindings.h"
#include "purp3D/scripting/lua/bindings/lualogbindings.h"
#include "purp3D/scripting/lua/bindings/luaeventbindings.h"
#include "purp3D/scripting/lua/bindings/luaenginebindings.h"
#include "purp3d/scripting/lua/bindings/luainputbindings.h"

namespace Purp3D
{
	void LuaBindings::RegisterAll(sol::state& lua)
	{
		lua["purp"] = lua.create_table();

		LuaLogBindings::Register(lua);
		LuaEventBindings::Register(lua);
		LuaEngineBindings::Register(lua);
		LuaInputBindings::Register(lua);
	}
}
