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
		virtual ~Layer() = default;

		// Called when an event is dispatched to this layer
		virtual void OnEvent(Event& event) {}

		// Called every frame with timestep
		virtual void OnUpdate(float ts) {}

		// Called every frame for rendering
		virtual void OnRender() {}

		// Replace this layer with a new one
		template<std::derived_from<Layer> T, typename... Args>
		void TransitionTo(Args&&... args)
		{
			QueueTransition(std::make_unique<T>(std::forward<Args>(args)...));
		}

	private:
		void QueueTransition(std::unique_ptr<Layer> newLayer);
	};
}

#endif