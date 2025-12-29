#ifndef LUA_BINDINGS_H
#define LUA_BINDINGS_H

#include "purp3d/core/core.h"
#include <sol/sol.hpp>

namespace Purp3D
{
	class LuaBindings
	{
	public:
		static void RegisterAll(sol::state& lua);
	};
}

#endif