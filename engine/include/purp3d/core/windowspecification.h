#ifndef WINDOW_SPECIFICATION_H
#define WINDOW_SPECIFICATION_H

#include "purp3d/core/core.h"

namespace Purp3D
{
	struct PURP_API WindowSpecification
	{
		const char* Title = nullptr;
		unsigned int Width = 1280;
		unsigned int Height = 720;
		bool VSync = true;
		bool Resizable = true;
	};
}
#endif