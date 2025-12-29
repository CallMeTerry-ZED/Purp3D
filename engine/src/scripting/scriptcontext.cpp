#include "purp3d/scripting/scriptcontext.h"
#include "purp3d/scripting/lua/luavm.h"

namespace Purp3D
{
	void ScriptContext::OnStart()
	{
		LuaVM::CallStart();
	}

	void ScriptContext::OnUpdate(float dt)
	{
		LuaVM::CallUpdate(dt);
	}

	void ScriptContext::OnEvent(ScriptEvent& event)
	{
		LuaVM::CallEvent(event);
	}
}
