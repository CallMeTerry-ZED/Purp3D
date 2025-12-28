#ifndef KEY_EVENTS_H
#define KEY_EVENTS_H

#include "purp3d/core/core.h"
#include "purp3d/core/events/event.h"

namespace Purp3D
{
	class PURP_API KeyEvent : public Event
	{
	public:
		int GetKeyCode() const { return m_KeyCode; }

	protected:
		KeyEvent(int keycode) : m_KeyCode(keycode)
		{

		}

		int m_KeyCode;
	};

	class PURP_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, bool repeat) : KeyEvent(keycode), IsRepeat(repeat)
		{

		}

		EVENT_CLASS_TYPE(KeyPressed)

		bool IsRepeat;
	};

	class PURP_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode) : KeyEvent(keycode)
		{

		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}

#endif