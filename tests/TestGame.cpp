#include "TestGame.hpp"

namespace Tano
{
    TestGame::TestGame(const sf::Vector2i& WindowSize, const std::string_view WindowTitle)
    {
        m_Engine.CreateInstance();

        const sf::Uint32 WindowStyle = sf::Style::Close;
        m_Engine.GetWindowManager().CreateWindow("Tano.TestGame.MainWindow", WindowSize, WindowTitle, WindowStyle);
    }

    TestGame::~TestGame()
    {
        m_Engine.Shutdown();
    }

    std::uint32_t TestGame::Start(int argc, char* argv[])
    {
        auto& WindowManager = m_Engine.GetWindowManager();
        WindowContext* Window = WindowManager.GetWindow("Tano.TestGame.MainWindow");

        Window->SetEventCallback([&](const sf::Event& Event)
        {
            if (Event.type == sf::Event::Closed)
            {
                WindowManager.DestroyWindow("Tano.TestGame.MainWindow");
            }
        });

        Window->SetUpdateCallback([&](const sf::Time& DeltaTime)
        {
            // Update Shenanigans
        });

        Window->Spawn();
        return EXIT_SUCCESS;
    }
} // namespace Tano