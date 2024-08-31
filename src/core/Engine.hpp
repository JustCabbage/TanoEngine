#pragma once
#include <SFML/Graphics.hpp>

#include "WindowManager.hpp"

#define TANO_VERSION "0.0.1"

namespace Tano
{
    class Engine
    {
    public:
        Engine() = default;
        ~Engine() = default;

    public:
        bool CreateInstance();
        void Shutdown();

        WindowManager& GetWindowManager()
        {
            return m_WindowManager;
        }

    private:
        WindowManager m_WindowManager;
    };
} // namespace Tano
