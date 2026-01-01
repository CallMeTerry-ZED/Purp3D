// Copyright (c) 2025-2026 ZED Interactive

#include "purp3d/core/log/logger.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Purp3D
{
	std::shared_ptr<spdlog::logger> Logger::PurpLogger;
	std::shared_ptr<spdlog::logger> Logger::PurpClientLogger;
	std::shared_ptr<spdlog::logger> Logger::PurpServerLogger;

	void Logger::Init()
	{
		// Log order is timestamp logger name and the actual message
		// Then it will be wrapped in whatever color the message should be
		spdlog::set_pattern("%^[%T] %n: %v%$");
		PurpLogger = spdlog::stdout_color_mt("PURP");
		PurpLogger->set_level(spdlog::level::trace);

		PurpClientLogger = spdlog::stdout_color_mt("CLIENT");
		PurpClientLogger->set_level(spdlog::level::trace);

		PurpServerLogger = spdlog::stdout_color_mt("SERVER");
		PurpServerLogger->set_level(spdlog::level::trace);
	}
}