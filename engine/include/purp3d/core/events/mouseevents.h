#ifndef MOUSE_EVENTS_H
#define MOUSE_EVENTS_H

#include "purp3d/core/core.h"
#include "purp3d/core/events/event.h"

namespace Purp3D
{
	class PURP_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y) : MouseX(x), MouseY(y)
		{

		}

		EVENT_CLASS_TYPE(MouseMoved)

		float MouseX;
		float MouseY;
	};

	class PURP_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset) : XOffset(xOffset), YOffset(yOffset)
		{

		}

		EVENT_CLASS_TYPE(MouseScrolled)

		float XOffset;
		float YOffset;
	};

	class PURP_API MouseButtonEvent : public Event
	{
	public:
		int GetMouseButton() const { return m_Button; }

	protected:
		MouseButtonEvent(int button) : m_Button(button)
		{

		}

		int m_Button;
	};

	class PURP_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button)
		{

		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class PURP_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button)
		{

		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}

#endif