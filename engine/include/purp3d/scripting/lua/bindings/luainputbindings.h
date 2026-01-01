// Copyright (c) 2025-2026 ZED Interactive

#ifndef LUA_INPUT_BINDINS
#define LUA_INPUT_BINDIGS

#include <sol/sol.hpp>

namespace Purp3D
{
	class LuaInputBindings
	{
	public:
		static void Register(sol::state& lua);
	};
}

#endif