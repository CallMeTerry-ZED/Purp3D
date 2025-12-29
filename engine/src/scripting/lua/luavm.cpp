#include "purp3d/scripting/lua/luavm.h"
#include "purp3d/scripting/lua/luabindings.h"
#include "purp3d/core/log/logger.h"

namespace Purp3D
{
	sol::state LuaVM::s_Lua;

	void LuaVM::Init()
	{
		s_Lua.open_libraries(
			sol::lib::base,
			sol::lib::math,
			sol::lib::table,
			sol::lib::string
		);

		LuaBindings::RegisterAll(s_Lua);

		try
		{
			s_Lua.script_file("assets/scripts/main.lua");
		}
		catch (const sol::error& e)
		{
			PURP_ERROR("Lua error: {}", e.what());
		}

		CallStart();
	}

	void LuaVM::Shutdown()
	{
	}

	void LuaVM::CallStart()
	{
		auto fn = s_Lua["purp"]["start"];
		if (fn.valid())
			fn();
	}

	void LuaVM::CallUpdate(float dt)
	{
		auto fn = s_Lua["purp"]["update"];
		if (fn.valid())
			fn(dt);
	}

	void LuaVM::CallEvent(ScriptEvent& event)
	{
		auto fn = s_Lua["purp"]["onevent"];
		if (!fn.valid())
			return;

		sol::table evt = s_Lua.create_table();
		evt["type"] = event.Type;
		evt["handled"] = false;

		fn(evt);

		event.Handled = evt["handled"].get_or(false);
	}

	sol::state& LuaVM::GetState()
	{
		return s_Lua;
	}
}