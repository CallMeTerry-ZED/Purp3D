#ifndef LUA_LOG_BINDINGS_H
#define LUA_LOG_BINDINGS_H

#include <sol/sol.hpp>

namespace Purp3D
{
	class LuaLogBindings
	{
	public:
		static void Register(sol::state& lua);
	};
}

#endif