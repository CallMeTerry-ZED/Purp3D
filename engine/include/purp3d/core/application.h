#ifndef APPLICATION_H
#define APPLICATION_H

#include "purp3d/core/core.h"
#include "purp3d/core/applicationspecification.h"
#include "purp3d/core/window.h"
#include "purp3d/core/events/eventqueue.h"
#include "purp3d/core/layer/layer.h"
#include "purp3d/renderer/glutils.h"
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

		template<typename TLayer>
		requires(std::is_base_of_v<Layer, TLayer>)
		void PushLayer()
		{
			m_LayerStack.push_back(std::make_unique<TLayer>());
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
		std::vector<std::unique_ptr<Layer>> m_LayerStack;

		friend class Layer;
		friend class GLUtils;
	};

	// This is to be defined by the CLIENT
	Application* CreateApplication();
}

#endif