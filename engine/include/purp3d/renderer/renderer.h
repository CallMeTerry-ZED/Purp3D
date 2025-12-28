#ifndef RENDERER_H
#define RENDERER_H

#include "purp3d/core/core.h"
#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <filesystem>

namespace Purp3D
{
	class PURP_API Renderer
	{
		struct Texture
		{
			GLuint Handle = 0;
			uint32_t Width = 0;
			uint32_t Height = 0;
		};

		struct Framebuffer
		{
			GLuint Handle = 0;
			Texture ColorAttachment;
		};

		Texture CreateTexture(int width, int height);
		Texture LoadTexture(const std::filesystem::path& path);
		Framebuffer CreateFramebufferWithTexture(const Texture texture);
		bool AttachTextureToFramebuffer(Framebuffer& framebuffer, const Texture texture);
		void BlitFramebufferToSwapchain(const Framebuffer framebuffer);
	};
}

#endif