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
            EntityDescriptor SomeEntity = ECS::CreateEntity();
            ECS::AddComponent<TransormComponent>(SomeEntity);
            ECS::AddComponent<CollideComponent>(SomeEntity);
            this->AddEntity(SomeEntity);
        }
        void HandleEvent(const sf::Event& Event) override
        {
        }
        void Update(std::uint32_t DeltaTime) override
        {
            for (const auto [Index, Entity] : std::views::enumerate(m_Entities))
            {
                if (ECS::HasComponent<CollideComponent>(Entity))
                {
                    TANO_LOG_INFO("Entity {0} has CollideComponent", Index);
                }

                if (ECS::HasComponent<TransormComponent>(Entity))
                {
                    TANO_LOG_INFO("Entity {0} has TransormComponent", Index);
                }
            }
        }
        void Render(sf::RenderWindow& Window) override
        {
        }
    };
} // namespace Tano