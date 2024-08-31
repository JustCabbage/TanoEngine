#include "WindowManager.hpp"

#include <utils/Debug.hpp>
#include <utils/Logging.hpp>

namespace Tano
{
    void WindowContext::SetEventCallback(const std::function<void(sf::Event)>& Callback)
    {
        TANO_ASSERT(Callback, "Invalid event callback");
        m_EventCallback = Callback;
    }

    void WindowContext::HandleEvents()
    {
        sf::Event Event;
        while (m_Window.pollEvent(Event))
        {
            if (m_EventCallback)
            {
                m_EventCallback(Event);
            }
        }
    }

    void WindowContext::SetUpdateCallback(const std::function<void(const sf::Time&)>& Callback)
    {
        TANO_ASSERT(Callback, "Invalid update callback");
        m_UpdateCallback = Callback;
    }

    void WindowContext::Spawn()
    {
        TANO_ASSERT(m_UpdateCallback, "Invalid update callback");
        while (m_Window.isOpen())
        {
            this->HandleEvents();
            const sf::Time DeltaTime = m_Clock.restart();
            if (m_UpdateCallback)
            {
                m_UpdateCallback(DeltaTime);
            }
            m_Window.display();
        }
    }

    sf::RenderWindow& WindowContext::GetWindow()
    {
        return m_Window;
    }

    bool WindowContext::IsOpen() const
    {
        return m_Window.isOpen();
    }

    void WindowContext::Close()
    {
        return m_Window.close();
    }

    void WindowContext::Destroy()
    {
        m_UpdateCallback = nullptr;
        m_EventCallback = nullptr;
        m_Window.close();
    }
} // namespace Tano

namespace Tano
{
    bool WindowManager::CreateWindow(const std::string_view WindowId, const sf::Vector2i& WindowSize, const std::string_view WindowTitle, const sf::Uint32 WindowStyle)
    {
        auto it = m_Windows.find(WindowId.data());
        if (it == m_Windows.end())
        {
            m_Windows[WindowId.data()] = std::make_unique<WindowContext>(sf::VideoMode(WindowSize.x, WindowSize.y), WindowTitle.data(), WindowStyle);
            TANO_LOG_INFO("WindowManager::CreateWindow() {} Created", WindowId);
            return m_Windows[WindowId.data()] != nullptr;
        }
        // Window already exists
        return false;
    }

    bool WindowManager::DestroyWindow(const std::string_view WindowId)
    {
        auto it = m_Windows.find(WindowId.data());
        if (it != m_Windows.end() && it->second->IsOpen())
        {
            it->second->Destroy();
            TANO_ASSERT(!m_Windows.find(WindowId.data())->second->IsOpen(), "Failed to destroy window");
            TANO_LOG_INFO("WindowManager::DestroyWindow() {} Destroyed", WindowId);
            return true;
        }
        // Window not found or already closed
        return false;
    }

    WindowContext* WindowManager::GetWindow(const std::string_view WindowId) const
    {
        auto it = m_Windows.find(WindowId.data());
        TANO_ASSERT(it != m_Windows.end(), "Window not found");
        if (it != m_Windows.end())
        {
            return it->second.get();
        }
        // Window not found
        return nullptr;
    }

    void WindowManager::Shutdown()
    {
        for (auto& [WindowId, Window] : m_Windows)
        {
            Window->Close();
        }
        m_Windows.clear();
        TANO_ASSERT(m_Windows.empty(), "Failed to shutdown window manager");
    }
} // namespace Tano