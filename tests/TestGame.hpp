#pragma once
#include <Tano/Core.hpp>
#include <Tano/Utils.hpp>

namespace Tano
{
    class TestGame
    {
    public:
        TestGame(const sf::Vector2i& WindowSize, const std::string_view WindowTitle);
        ~TestGame();

    public:
        std::uint32_t Start(int argc, char* argv[]);

    private:
        Tano::Engine m_Engine;
    };
} // namespace Tano