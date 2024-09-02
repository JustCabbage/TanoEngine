#pragma once
#include <Tano/Core.hpp>
#include <Tano/Scene.hpp>
#include <Tano/Utils.hpp>

namespace Tano
{
    class TestScene : public Scene
    {
    public:
        TestScene(const std::string_view SceneId) : Scene(SceneId)
        {
        }
        void HandleEvent(const sf::Event& Event) override
        {
        }
        void Update(std::uint32_t DeltaTime) override
        {
        }
        void Render(sf::RenderWindow& Window) override
        {
        }
    };
} // namespace Tano