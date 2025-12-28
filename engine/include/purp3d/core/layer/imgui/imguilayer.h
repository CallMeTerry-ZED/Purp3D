#ifndef IMGUI_LAYER_H
#define IMGUI_LAYER_H

#include "purp3d/core/core.h"
#include "purp3d/core/layer/layer.h"
#include "purp3d/core/events/keyevents.h"
#include "purp3d/core/events/mouseevents.h"

namespace Purp3D
{
	class PURP_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float Time = 0.0f;
	};
}

#endif