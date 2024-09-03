#pragma once
#include <SFML/Graphics.hpp>

namespace Tano
{
    struct TransormComponent
    {
        sf::Vector2f Position = {0.f, 0.f};
        sf::Vector2f Scale = {1.f, 1.f};
        float Rotation = 0.f;
    };
} // namespace Tano