#ifndef LAYER_STACK_H
#define LAYER_STACK_H

#include "purp3d/core/core.h"
#include "purp3d/core/layer/layer.h"
#include <vector>
#include <memory>

namespace Purp3D
{
	class PURP_API LayerStack
	{
	public:
		using LayerPtr = std::unique_ptr<Layer>;

		LayerStack() = default;
		~LayerStack() = default;

		void PushLayer(LayerPtr layer);
		void PushOverlay(LayerPtr overlay);

		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		void ReplaceLayer(Layer* oldLayer, LayerPtr newLayer);

		auto begin() { return m_Layers.begin(); }
		auto end() { return m_Layers.end(); }
		auto rbegin() { return m_Layers.rbegin(); }
		auto rend() { return m_Layers.rend(); }

	private:
		std::vector<LayerPtr> m_Layers;
		size_t m_LayerInsertIndex = 0;
	};
}

#endif