// Copyright (c) 2025-2026 ZED Interactive

#ifndef WINDOW_H
#define WINDOW_H

#include "purp3d/core/core.h"
#include "purp3d/core/windowspecification.h"
#include "purp3d/core/events/event.h"
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <string>
#include <functional>
#include <memory>

namespace Purp3D
{
	class PURP_API Window
	{
	public:
		using EventCallbackFn = std::function<void(std::unique_ptr<Event>)>;

		Window(const WindowSpecification& specification = WindowSpecification());
		~Window();

		void Create();
		void Destroy();

		void Update();

		void SetEventCallback(const EventCallbackFn& callback)
		{
			m_EventCallback = callback;
		}

		glm::vec2 GetFramebufferSize() const;
		glm::vec2 GetMousePos() const;

		bool ShouldClose() const;

		GLFWwindow* GetHandle() const { return m_Handle; }
	private:
		WindowSpecification m_spec;
		GLFWwindow* m_Handle = nullptr;
		EventCallbackFn m_EventCallback;

	};
}

#endif