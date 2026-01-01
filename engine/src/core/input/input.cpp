// Copyright (c) 2025-2026 ZED Interactive

#include "purp3d/core/input/input.h"
#include "purp3d/core/application.h"
#include <GLFW/glfw3.h>

namespace Purp3D
{
	bool Input::IsKeyPressed(int keycode)
	{
		auto window = Application::Get().GetWindow()->GetHandle();
		int state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool Input::IsMouseButtonPressed(int button)
	{
		auto window = Application::Get().GetWindow()->GetHandle();
		int state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	glm::vec2 Input::GetMousePosition()
	{
		auto window = Application::Get().GetWindow()->GetHandle();
		double x, y;
		glfwGetCursorPos(window, &x, &y);
		return { (float)x, (float)y };
	}

	float Input::GetMouseX()
	{
		return GetMousePosition().x;
	}

	float Input::GetMouseY()
	{
		return GetMousePosition().y;
	}
}