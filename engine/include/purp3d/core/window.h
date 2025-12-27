#ifndef WINDOW_H
#define WINDOW_H

#include "purp3d/core/core.h"
#include "purp3d/core/windowspecification.h"
#include <GLFW/glfw3.h>
#include <string>
#include <functional>

namespace Purp3D
{
	class PURP_API Window
	{
	public:
		Window(const WindowSpecification& specification = WindowSpecification());
		~Window();

		void Create();
		void Destroy();

		void Update();

		bool ShouldClose() const;

		GLFWwindow* GetHandle() const { return m_Handle; }
	private:
		WindowSpecification m_spec;
		GLFWwindow* m_Handle = nullptr;

	};
}

#endif