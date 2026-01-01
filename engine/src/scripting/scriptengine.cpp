// Copyright (c) 2025-2026 ZED Interactive

#include "purp3d/scripting/scriptengine.h"
#include "purp3d/scripting/scriptcontext.h"
#include "purp3d/scripting/lua/luavm.h"
#include <purp3d/core/events/mouseevents.h>
#include <purp3d/core/events/keyevents.h>
#include <purp3d/core/events/windowevents.h>

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

		switch (e.GetEventType())
		{
			case EventType::KeyPressed:
			{
				auto& ev = static_cast<KeyPressedEvent&>(e);
				se.KeyCode = ev.GetKeyCode();
				se.Repeat = ev.IsRepeat;
				break;
			}
			case EventType::KeyReleased:
			{
				auto& ev = static_cast<KeyReleasedEvent&>(e);
				se.KeyCode = ev.GetKeyCode();
				break;
			}
			case EventType::MouseButtonPressed:
			{
				auto& ev = static_cast<MouseButtonPressedEvent&>(e);
				se.MouseButton = ev.GetMouseButton();
				break;
			}
			case EventType::MouseButtonReleased:
			{
				auto& ev = static_cast<MouseButtonReleasedEvent&>(e);
				se.MouseButton = ev.GetMouseButton();
				break;
			}
			case EventType::MouseMoved:
			{
				auto& ev = static_cast<MouseMovedEvent&>(e);
				se.MouseX = ev.MouseX;
				se.MouseY = ev.MouseY;
				break;
			}
			case EventType::MouseScrolled:
			{
				auto& ev = static_cast<MouseScrolledEvent&>(e);
				se.ScrollX = ev.XOffset;
				se.ScrollY = ev.YOffset;
				break;
			}
			case EventType::WindowResize:
			{
				auto& ev = static_cast<WindowResizeEvent&>(e);
				se.Width = ev.Width;
				se.Height = ev.Height;
				break;
			}
		}

		ScriptContext::OnEvent(se);

		if (se.Handled)
			e.Handled = true;
	}
}
