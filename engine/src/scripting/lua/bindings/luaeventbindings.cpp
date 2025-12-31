#include "purp3D/scripting/lua/bindings/luaeventbindings.h"
#include "purp3d/core/events/event.h"

namespace Purp3D
{
	void LuaEventBindings::Register(sol::state& lua)
	{
		auto purp = lua["purp"];

		sol::table event = lua.create_table();

		// ---- EventType enum bindings ----
		event["None"] = (int)EventType::None;
		event["WindowClose"] = (int)EventType::WindowClose;
		event["WindowResize"] = (int)EventType::WindowResize;
		event["KeyPressed"] = (int)EventType::KeyPressed;
		event["KeyReleased"] = (int)EventType::KeyReleased;
		event["MouseButtonPressed"] = (int)EventType::MouseButtonPressed;
		event["MouseButtonReleased"] = (int)EventType::MouseButtonReleased;
		event["MouseMoved"] = (int)EventType::MouseMoved;
		event["MouseScrolled"] = (int)EventType::MouseScrolled;

		// ---- Helpers ----
		event["mark_handled"] = [](sol::table evt)
		{
			evt["handled"] = true;
		};

		event["is_key_pressed"] = [](sol::table evt, int keycode)
		{
			return evt["type"] == (int)EventType::KeyPressed &&
				evt.get_or("keycode", -1) == keycode;
		};

		event["is_key_released"] = [](sol::table evt, int keycode)
		{
			return evt["type"] == (int)EventType::KeyReleased &&
				evt.get_or("keycode", -1) == keycode;
		};

		purp["event"] = event;
	}
}
