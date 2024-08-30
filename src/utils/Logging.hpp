#pragma once
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include <map>
#include <memory>

namespace Tano
{
    class Logging
    {
    public:
        Logging() = delete;
        ~Logging() = delete;

    public:
        static void Create(const std::string_view LoggerName = "Tano");
        static std::shared_ptr<spdlog::logger>& GetLogger(const std::string_view LoggerName = "Tano");
        static void Shutdown();

    private:
        static std::map<std::string, std::shared_ptr<spdlog::logger>> s_Loggers;
    };

} // namespace Tano

#ifdef TANO_DEBUG
#define TANO_LOG_TRACE(...) ::Tano::Logging::GetLogger()->trace(__VA_ARGS__)
#define TANO_LOG_INFO(...) ::Tano::Logging::GetLogger()->info(__VA_ARGS__)
#define TANO_LOG_WARN(...) ::Tano::Logging::GetLogger()->warn(__VA_ARGS__)
#define TANO_LOG_ERROR(...) ::Tano::Logging::GetLogger()->error(__VA_ARGS__)
#define TANO_LOG_CRITICAL(...) ::Tano::Logging::GetLogger()->critical(__VA_ARGS__)

// Ensure that the logger exists before logging to any custom prefixed logger

#define TANO_LOG_TRACE_LOGGER(logger, ...) ::Tano::Logging::GetLogger(logger)->trace(__VA_ARGS__)
#define TANO_LOG_INFO_LOGGER(logger, ...) ::Tano::Logging::GetLogger(logger)->info(__VA_ARGS__)
#define TANO_LOG_WARN_LOGGER(logger, ...) ::Tano::Logging::GetLogger(logger)->warn(__VA_ARGS__)
#define TANO_LOG_ERROR_LOGGER(logger, ...) ::Tano::Logging::GetLogger(logger)->error(__VA_ARGS__)
#define TANO_LOG_CRITICAL_LOGGER(logger, ...) ::Tano::Logging::GetLogger(logger)->critical(__VA_ARGS__)

#else
#define TANO_LOG_TRACE(...)
#define TANO_LOG_INFO(...)
#define TANO_LOG_WARN(...)
#define TANO_LOG_ERROR(...)
#define TANO_LOG_CRITICAL(...)

#define TANO_LOG_TRACE_LOGGER(logger, ...)
#define TANO_LOG_INFO_LOGGER(logger, ...)
#define TANO_LOG_WARN_LOGGER(logger, ...)
#define TANO_LOG_ERROR_LOGGER(logger, ...)
#define TANO_LOG_CRITICAL_LOGGER(logger, ...)
#endif