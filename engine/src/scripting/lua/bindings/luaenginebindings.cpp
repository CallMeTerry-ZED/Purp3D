#include "purp3D/scripting/lua/bindings/luaenginebindings.h"
#include "purp3d/core/application.h"

namespace Purp3D
{
	void LuaEngineBindings::Register(sol::state& lua)
	{
		// This is just a sol::table_proxy type
		auto purp = lua["purp"];

		purp["quit"] = []()
		{
				Application::Get().Stop();
		};
	}
}