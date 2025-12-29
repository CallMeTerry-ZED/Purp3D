#include "purp3D/scripting/lua/bindings/lualogbindings.h"
#include "purp3d/core/log/logger.h"

namespace Purp3D
{
	void LuaLogBindings::Register(sol::state& lua)
	{
		auto purp = lua["purp"];

		purp["clientlog"] = lua.create_table_with(
			"trace", [](const std::string& m) { PURP_CLIENT_TRACE(m); },
			"info", [](const std::string& m) { PURP_CLIENT_INFO(m);  },
			"warn", [](const std::string& m) { PURP_CLIENT_WARN(m);  },
			"error", [](const std::string& m) { PURP_CLIENT_ERROR(m); }
		);

		purp["serverlog"] = lua.create_table_with(
			"trace", [](const std::string& m) { PURP_SERVER_TRACE(m); },
			"info", [](const std::string& m) { PURP_SERVER_INFO(m);  },
			"warn", [](const std::string& m) { PURP_SERVER_WARN(m);  },
			"error", [](const std::string& m) { PURP_SERVER_ERROR(m); }
		);
	}
}