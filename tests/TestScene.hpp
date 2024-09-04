#pragma once
#include <Tano/Core.hpp>
#include <Tano/EntityComponentSystem.hpp>
#include <Tano/Scene.hpp>
#include <Tano/Utils.hpp>
#include <ranges>

namespace Tano
{
    class TestScene : public Scene
    {
    public:
        TestScene(const std::string_view SceneId) : Scene(SceneId)
        {
            EntityDescriptor SomeEntity = CreateEntity<TransformComponent, CollideComponent>();
            this->AddEntity(SomeEntity);
        }
        void HandleEvent(const sf::Event& Event) override
        {
        }
        void Update(std::uint32_t DeltaTime) override
        {
            for (const auto [Index, Entity] : std::views::enumerate(m_Entities))
            {
                if (Entity.HasComponent<TransformComponent>())
                {
                    TANO_LOG_INFO("Entity {0} has TransformComponent", Index);
                }

                if (Entity.HasComponent<CollideComponent>())
                {
                    TANO_LOG_INFO("Entity {0} has CollideComponent", Index);
                }
            }
        }
        void Render(sf::RenderWindow& Window) override
        {
        }
    };
} // namespace Tano