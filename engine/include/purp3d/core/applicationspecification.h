#ifndef APPLICATION_SPECIFICATION_H
#define APPLICATION_SPECIFICATION_H

#include "purp3d/core/core.h"
#include "purp3d/core/windowspecification.h"

namespace Purp3D
{
	struct PURP_API ApplicationSpecification
	{
		const char* Name = "Purp3D Application";
		WindowSpecification WindowSpec;
	};
}

#endif