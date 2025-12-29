#ifndef LUA_ENGINE_BINDINGS_H
#define LUA_ENGINE_BINDINGS_H

#include <sol/sol.hpp>

namespace Purp3D
{
	class LuaEngineBindings
	{
	public:
		static void Register(sol::state& lua);
	};
}

#endif