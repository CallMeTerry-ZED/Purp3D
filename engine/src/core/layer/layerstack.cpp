#include "purp3d/core/layer/layerstack.h"

namespace Purp3D
{
	void LayerStack::PushLayer(LayerPtr layer)
	{
		layer->OnAttach();
		m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, std::move(layer));
		m_LayerInsertIndex++;
	}

	void LayerStack::PushOverlay(LayerPtr overlay)
	{
		overlay->OnAttach();
		m_Layers.emplace_back(std::move(overlay));
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		for (auto it = m_Layers.begin(); it != m_Layers.end(); ++it)
		{
			if (it->get() == layer)
			{
				(*it)->OnDetach();
				m_Layers.erase(it);
				m_LayerInsertIndex--;
				return;
			}
		}
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		for (auto it = m_Layers.begin(); it != m_Layers.end(); ++it)
		{
			if (it->get() == overlay)
			{
				(*it)->OnDetach();
				m_Layers.erase(it);
				return;
			}
		}
	}

	void LayerStack::ReplaceLayer(Layer* oldLayer, LayerPtr newLayer)
	{
		for (auto& layer : m_Layers)
		{
			if (layer.get() == oldLayer)
			{
				layer->OnDetach();
				newLayer->OnAttach();
				layer = std::move(newLayer);
				return;
			}
		}
	}

}