#ifndef LOGGER_H
#define LOGGER_H

#include "purp3d/core/core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Purp3D
{
	class PURP_API Logger
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetPurpLogger() { return PurpLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetPurpClientLogger() { return PurpClientLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetPurpServerLogger() { return PurpServerLogger; }

	private:
		static std::shared_ptr<spdlog::logger> PurpLogger;
		static std::shared_ptr<spdlog::logger> PurpClientLogger;
		static std::shared_ptr<spdlog::logger> PurpServerLogger;
	};

	// TODO: Add file logging and change INFO AND WARN
	// To be blue and magenta respectively

	// Core log macros
	#define PURP_CRITICAL(...)	::Purp3D::Logger::GetPurpLogger()->critical(__VA_ARGS__) //Red
	#define PURP_ERROR(...)		::Purp3D::Logger::GetPurpLogger()->error(__VA_ARGS__)	 //Red
	#define PURP_WARN(...)		::Purp3D::Logger::GetPurpLogger()->warn(__VA_ARGS__)	 //Yellow
	#define PURP_INFO(...)		::Purp3D::Logger::GetPurpLogger()->info(__VA_ARGS__)	 //Green
	#define PURP_TRACE(...)		::Purp3D::Logger::GetPurpLogger()->trace(__VA_ARGS__)	 //White

	// Client log macros
	#define PURP_CLIENT_CRITICAL(...)	::Purp3D::Logger::GetPurpClientLogger()->critical(__VA_ARGS__)	//Red
	#define PURP_CLIENT_ERROR(...)		::Purp3D::Logger::GetPurpClientLogger()->error(__VA_ARGS__)		//Red
	#define PURP_CLIENT_WARN(...)		::Purp3D::Logger::GetPurpClientLogger()->warn(__VA_ARGS__)		//Yellow
	#define PURP_CLIENT_INFO(...)		::Purp3D::Logger::GetPurpClientLogger()->info(__VA_ARGS__)		//Green
	#define PURP_CLIENT_TRACE(...)		::Purp3D::Logger::GetPurpClientLogger()->trace(__VA_ARGS__)		//White

	// Client log macros
	#define PURP_SERVER_CRITICAL(...)	::Purp3D::Logger::GetPurpServerLogger()->critical(__VA_ARGS__)	//Red
	#define PURP_SERVER_ERROR(...)		::Purp3D::Logger::GetPurpServerLogger()->error(__VA_ARGS__)		//Red
	#define PURP_SERVER_WARN(...)		::Purp3D::Logger::GetPurpServerLogger()->warn(__VA_ARGS__)		//Yellow
	#define PURP_SERVER_INFO(...)		::Purp3D::Logger::GetPurpServerLogger()->info(__VA_ARGS__)		//Green
	#define PURP_SERVER_TRACE(...)		::Purp3D::Logger::GetPurpServerLogger()->trace(__VA_ARGS__)		//White
}

#endif