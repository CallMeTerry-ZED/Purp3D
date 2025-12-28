#ifndef GL_UTILS_H
#define GL_UTILS_H

#include "purp3d/core/core.h"
#include <glad/gl.h>

namespace Purp3D
{
	class PURP_API GLUtils
	{
	public:
		static const char* GLDebugSourceToString(GLenum source);
		static const char* GLDebugTypeToString(GLenum type);
		static const char* GLDebugSeverityToString(GLenum severity);
		static void InitOpenGLDebugMessageCallback();
	};
}

#endif