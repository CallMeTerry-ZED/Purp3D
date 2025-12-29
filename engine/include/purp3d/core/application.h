#ifndef APPLICATION_H
#define APPLICATION_H

#include "purp3d/core/core.h"
#include "purp3d/core/applicationspecification.h"
#include "purp3d/core/window.h"
#include "purp3d/core/events/eventqueue.h"
#include "purp3d/core/layer/layer.h"
#include "purp3d/core/layer/layerstack.h"
#include "purp3d/core/layer/imgui/imguilayer.h"
#include "purp3d/renderer/glutils.h"
#include "purp3d/scripting/scriptengine.h"
#include <glm/glm.hpp>
#include <memory>
#include <vector>


namespace Purp3D
{
	class PURP_API Application
	{
	public:
		Application(const ApplicationSpecification& specification = ApplicationSpecification());
		virtual ~Application();

		void Run();
		void Stop();

		template<typename T, typename... Args>
		T* PushLayer(Args&&... args)
		{
			auto layer = std::make_unique<T>(std::forward<Args>(args)...);
			T* ptr = layer.get();
			m_LayerStack.PushLayer(std::move(layer));
			return ptr;
		}

		template<typename T, typename... Args>
		T* PushOverlay(Args&&... args)
		{
			auto overlay = std::make_unique<T>(std::forward<Args>(args)...);
			T* ptr = overlay.get();
			m_LayerStack.PushOverlay(std::move(overlay));
			return ptr;
		}

		template<typename T, typename... Args>
		void ReplaceLayer(Layer* oldLayer, Args&&... args)
		{
			m_LayerStack.ReplaceLayer(
				oldLayer,
				std::make_unique<T>(std::forward<Args>(args)...)
			);
		}

		static Application& Get();
		static float GetTime();
		glm::vec2 GetFramebufferSize() const;
		std::shared_ptr<Window> GetWindow() const { return m_Window; }

	private:
		void ProcessEvents();

		static Application* s_Instance;
		ApplicationSpecification m_spec;
		std::shared_ptr<Window> m_Window;
		EventQueue m_EventQueue;
		bool m_Running = false;
		ImGuiLayer* m_ImGuiLayer;
		LayerStack m_LayerStack;

		friend class Layer;
		friend class ImGuiLayer;
		friend class GLUtils;
	};

	// This is to be defined by the CLIENT
	Application* CreateApplication();
}

#endif