#include "WindowManager.hpp"

#include <utils/Debug.hpp>

namespace Tano
{

    void WindowContext::SetEventCallback(const std::function<void(sf::Event)>& Callback)
    {
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
            return m_Windows[WindowId.data()] != nullptr;
        }
        // Window already exists
        return false;
    }

    bool WindowManager::DestroyWindow(const std::string_view WindowId)
    {
        auto it = m_Windows.find(WindowId.data());
        if (it != m_Windows.end())
        {
            it->second->Destroy();
            TANO_ASSERT(!m_Windows.find(WindowId.data())->second->IsOpen(), "Failed to destroy window");
            return true;
        }
        // Window not found
        return false;
    }

    WindowContext* WindowManager::GetWindow(const std::string_view WindowId) const
    {
        auto it = m_Windows.find(WindowId.data());
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