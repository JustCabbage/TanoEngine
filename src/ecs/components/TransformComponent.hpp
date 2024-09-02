#pragma once
#include <SFML/Graphics.hpp>

namespace Tano
{
    struct TransormComponent
    {
        sf::Vector2f Position;
        sf::Vector2f Scale;
        float Rotation;
    };
} // namespace Tano