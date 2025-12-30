#ifndef INPUT_H
#define INPUT_H

#include "purp3d/core/core.h"
#include <glm/glm.hpp>

namespace Purp3D
{
	class PURP_API Input
	{
	public:
		// Keyboard
		static bool IsKeyPressed(int keycode);

		// Mouse
		static bool IsMouseButtonPressed(int button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}

#endif