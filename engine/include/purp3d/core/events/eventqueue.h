// Copyright (c) 2025-2026 ZED Interactive

#ifndef EVENT_QUEUE_H
#define EVENT_QUEUE_H

#include "purp3d/core/core.h"
#include "purp3d/core/events/event.h"
#include <queue>
#include <memory>

namespace Purp3D
{
	class PURP_API EventQueue
	{
	public:
		void Push(std::unique_ptr<Event> event)
		{
			m_Queue.push(std::move(event));
		}

		bool Empty() const
		{
			return m_Queue.empty();
		}

		std::unique_ptr<Event> Pop()
		{
			auto event = std::move(m_Queue.front());
			m_Queue.pop();
			return event;
		}

		void Clear()
		{
			while (!m_Queue.empty())
			{
				m_Queue.pop();
			}
		}

	private:
		std::queue<std::unique_ptr<Event>> m_Queue;
	};
}

#endif