#ifndef LUA_EVENT_BINDINGS_H
#define LUA_EVENT_BINDINGS_H

#include <sol/sol.hpp>

namespace Purp3D
{
	class LuaEventBindings
	{
	public:
		static void Register(sol::state& lua);
	};
}

#endif