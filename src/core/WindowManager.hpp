#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <memory>
#include <string_view>
#include <unordered_map>

namespace Tano
{
    class WindowContext
    {
    public:
        WindowContext(sf::VideoMode VideoMode, const std::string_view WindowTitle, const sf::Uint32 WindowStyle = sf::Style::Default)
            : m_Window(VideoMode, WindowTitle.data(), WindowStyle) {};
        ~WindowContext() = default;

    public:
        void SetEventCallback(const std::function<void(sf::Event)>& Callback);
        void SetUpdateCallback(const std::function<void(const sf::Time&)>& Callback);
        sf::RenderWindow& GetWindow();
        bool IsOpen() const;
        void Close();
        void Destroy();
        void Spawn();

    private:
        void HandleEvents();

    private:
        sf::RenderWindow m_Window;
        sf::Clock m_Clock;
        std::function<void(sf::Event)> m_EventCallback;
        std::function<void(const sf::Time&)> m_UpdateCallback;
    };

    class WindowManager
    {
    public:
        WindowManager() = default;
        ~WindowManager() = default;

    public:
        bool CreateWindow(const std::string_view WindowId, const sf::Vector2i& WindowSize, const std::string_view WindowTitle, const sf::Uint32 WindowStyle = sf::Style::Default);
        bool DestroyWindow(const std::string_view WindowId);
        void Shutdown();

        WindowContext* GetWindow(const std::string_view WindowId) const;

    private:
        std::unordered_map<std::string, std::unique_ptr<WindowContext>> m_Windows;
    };
} // namespace Tano