#include "Engine.hpp"

#include <utils/Logging.hpp>

namespace Tano
{
    bool Engine::CreateInstance()
    {
        Tano::Logging::Create("Tano");
        TANO_LOG_INFO("Welcome to Tano Engine! You are running version {}", TANO_VERSION);
        TANO_LOG_INFO("Engine::CreateInstance()");

        // Other engine initialization later

        return true;
    }

    void Engine::Shutdown()
    {
        TANO_LOG_INFO("Engine::Shutdown()");

        m_WindowManager.Shutdown();
        Tano::Logging::Shutdown();

        // Other engine shutdown later
    }
} // namespace Tano