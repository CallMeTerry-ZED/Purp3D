// Copyright (c) 2025-2026 ZED Interactive

#ifndef EVENT_H
#define EVENT_H

#include "purp3d/core/core.h"
#include <string>

namespace Purp3D
{
	enum class PURP_API EventType
	{
		None = 0,
		WindowClose, WindowResize,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased,
		MouseMoved, MouseScrolled
	};

#define EVENT_CLASS_TYPE(type)                                   \
    static EventType GetStaticType() { return EventType::type; } \
    virtual EventType GetEventType() const override { return GetStaticType(); } \
    virtual const char* GetName() const override { return #type; }

	class PURP_API Event
	{
	public:
		virtual ~Event() = default;

		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
	};
}

#endif