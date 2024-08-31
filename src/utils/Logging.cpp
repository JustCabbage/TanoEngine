#include "Logging.hpp"

#include <utils/Debug.hpp>

namespace Tano
{
    std::map<std::string, std::shared_ptr<spdlog::logger>> Logging::s_Loggers;

    void Logging::Create(const std::string_view LoggerName)
    {
        spdlog::set_pattern("[%Y-%m-%d %H:%M:%S] [%^%l%$] [%n] %v");
        s_Loggers.insert({LoggerName.data(), spdlog::stdout_color_mt(LoggerName.data())});
        s_Loggers[LoggerName.data()]->set_level(spdlog::level::trace);
        TANO_ASSERT(s_Loggers.find(LoggerName.data()) != s_Loggers.end());
        TANO_ASSERT(s_Loggers.at(LoggerName.data()) != nullptr);
    }
    std::shared_ptr<spdlog::logger>& Logging::GetLogger(const std::string_view LoggerName)
    {
        TANO_ASSERT(s_Loggers.find(LoggerName.data()) != s_Loggers.end(), "Logger doesn't exist. Please use Logging::Create(...) before using it");
        return s_Loggers.at(LoggerName.data());
    }
    void Logging::Shutdown()
    {
        s_Loggers.clear();
        TANO_ASSERT(s_Loggers.empty(), "Failed to shutdown logger");
    }
} // namespace Tano