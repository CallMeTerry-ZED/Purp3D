#ifndef EVENT_DISPATCHER_H
#define EVENT_DISPATCHER_H

#include "purp3d/core/core.h"
#include "purp3d/core/events/event.h"
#include <functional>

namespace Purp3D
{
	class PURP_API EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event) : m_Event(event)
		{

		}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType() && !m_Event.Handled)
			{
				m_Event.Handled = func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};
}

#endif