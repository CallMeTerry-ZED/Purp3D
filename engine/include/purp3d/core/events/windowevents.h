#ifndef WINDOW_EVENTS_H
#define WINDOW_EVENTS_H

#include "purp3d/core/core.h"
#include "purp3d/core/events/event.h"
#include <cstdint>

namespace Purp3D
{
	class PURP_API WindowCloseEvent : public Event
	{
	public:
		EVENT_CLASS_TYPE(WindowClose)
	};

	class PURP_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(uint32_t width, uint32_t height) : Width(width), Height(height)
		{

		}

		EVENT_CLASS_TYPE(WindowResize)

		uint32_t Width, Height;
	};
}

#endif