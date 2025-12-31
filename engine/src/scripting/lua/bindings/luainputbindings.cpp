#include "purp3d/scripting/lua/bindings/luainputbindings.h"
#include "purp3d/core/input/input.h"
#include "purp3d/core/input/keycodes.h"
#include "purp3d/core/input/mousecodes.h"
#include <glm/vec2.hpp>

namespace Purp3D
{
	void LuaInputBindings::Register(sol::state& lua)
	{
		auto purp = lua["purp"];

		auto input = lua.create_table();

		// ----- POLLING -----
		input["is_key_pressed"] = [](int keycode) -> bool
		{
			return Purp3D::Input::IsKeyPressed(keycode);
		};

		input["is_mouse_button_pressed"] = [](int button) -> bool
		{
			return Purp3D::Input::IsMouseButtonPressed(button);
		};

		input["get_mouse_position"] = [&lua]() -> sol::table
		{
			glm::vec2 pos = Purp3D::Input::GetMousePosition();
			sol::table t = lua.create_table();
			t["x"] = pos.x;
			t["y"] = pos.y;
			return t;
		};

		input["get_mouse_x"] = []() -> float
		{
			return Purp3D::Input::GetMouseX();
		};

		input["get_mouse_y"] = []() -> float
		{
			return Purp3D::Input::GetMouseY();
		};

		purp["input"] = input;

		// ----- CONSTANTS -----
		auto keys = lua.create_table_with(
			"TAB", PURP_KEY_TAB,
			"W", PURP_KEY_W,
			"A", PURP_KEY_A,
			"S", PURP_KEY_S,
			"D", PURP_KEY_D,
			"SPACE", PURP_KEY_SPACE,
			"ESCAPE", PURP_KEY_ESCAPE,
			"BACKSPACE", PURP_KEY_BACKSPACE
		);

		auto mouse = lua.create_table_with(
			"LEFT", PURP_MOUSE_BUTTON_LEFT,
			"RIGHT", PURP_MOUSE_BUTTON_RIGHT,
			"MIDDLE", PURP_MOUSE_BUTTON_MIDDLE,
			"BUTTON_1", PURP_MOUSE_BUTTON_1,
			"BUTTON_2", PURP_MOUSE_BUTTON_2

		);

		purp["key"] = keys;
		purp["mouse"] = mouse;
	}
}