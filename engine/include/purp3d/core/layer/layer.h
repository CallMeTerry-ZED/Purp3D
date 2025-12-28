#ifndef LAYER_H
#define LAYER_H

#include "purp3d/core/core.h"
#include "purp3d/core/events/event.h"
#include <memory>
#include <functional>

namespace Purp3D
{
	class PURP_API Layer
	{
	public:
		Layer(const char* name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}

		// Called when an event is dispatched to this layer
		virtual void OnEvent(Event& event) {}

		// Called every frame with timestep
		virtual void OnUpdate(float ts) {}

		// Called every frame for rendering
		virtual void OnRender() {}

		inline const char* GetName() { return m_DebugName; }

	private:
		const char* m_DebugName;
	};
}

#endif