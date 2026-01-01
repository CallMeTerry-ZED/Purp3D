// Copyright (c) 2025-2026 ZED Interactive

#ifndef SHADER_H
#define SHADER_H

#include "purp3d/core/core.h"
#include <filesystem>

namespace Purp3D
{
	class PURP_API Shader
	{
	public:
		static uint32_t CreateComputeShader(const std::filesystem::path& path);
		static uint32_t ReloadComputeShader(uint32_t shaderHandle, const std::filesystem::path& path);

		static uint32_t CreateGraphicsShader(const std::filesystem::path& vertexPath, const std::filesystem::path& fragmentPath);
		static uint32_t ReloadGraphicsShader(uint32_t shaderHandle, const std::filesystem::path& vertexPath, const std::filesystem::path& fragmentPath);
	};
}

#endif