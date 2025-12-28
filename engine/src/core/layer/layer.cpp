#include "purp3d/core/layer/layer.h"
#include "purp3d/core/application.h"

namespace Purp3D
{
	Layer::Layer(const char* debugName) : m_DebugName(debugName)
	{

	}

	void Layer::QueueTransition(std::unique_ptr<Layer> newLayer)
	{
		// TODO: don't do this
		auto& layerStack = Application::Get().m_LayerStack;
		for (auto& layer : layerStack)
		{
			if (layer.get() == this)
			{
				layer = std::move(newLayer);
				return;
			}
		}
	}
}
