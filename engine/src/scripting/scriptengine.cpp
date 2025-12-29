#include "purp3d/scripting/scriptengine.h"
#include "purp3d/scripting/scriptcontext.h"
#include "purp3d/scripting/lua/luavm.h"

namespace Purp3D
{
	void ScriptEngine::Init()
	{
		LuaVM::Init();
	}

	void ScriptEngine::Shutdown()
	{
		LuaVM::Shutdown();
	}

	void ScriptEngine::OnStart()
	{
		ScriptContext::OnStart();
	}

	void ScriptEngine::OnUpdate(float dt)
	{
		ScriptContext::OnUpdate(dt);
	}

	void ScriptEngine::OnEvent(Event& e)
	{
		ScriptEvent se;
		se.Type = (int)e.GetEventType();
		se.Handled = false;

		ScriptContext::OnEvent(se);

		if (se.Handled)
			e.Handled = true;
	}
}
