#include "TestGame.hpp"

namespace Tano
{
    TestGame::TestGame(const sf::Vector2i& WindowSize, const std::string_view WindowTitle)
    {
        m_Engine.CreateInstance();
        const sf::Uint32 WindowStyle = sf::Style::Close;

        m_Engine.GetWindowManager().CreateWindow("Tano.TestGame.MainWindow", WindowSize, WindowTitle, WindowStyle);
        m_Engine.CreateScene<TestScene>("Tano.TestGame.TestScene");
    }

    TestGame::~TestGame()
    {
        m_Engine.Shutdown();
    }

    std::uint32_t TestGame::Start(int argc, char* argv[])
    {
        m_Engine.SetActiveScene("Tano.TestGame.TestScene");

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
            m_Engine.UpdateScene(DeltaTime.asMilliseconds());
            auto Scene = m_Engine.GetActiveScene();
            if (Scene)
            {
                Scene->Render(Window->GetWindow());
            }
        });

        Window->Spawn();
        return EXIT_SUCCESS;
    }
} // namespace Tano