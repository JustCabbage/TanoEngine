#include "TestScene.hpp"

namespace Tano
{
    TestScene::TestScene(const std::string_view SceneId) : Scene(SceneId)
    {
        EntityDescriptor SomeEntity = m_EntityContainer.CreateEntity<TransformComponent, CollideComponent>();
        EntityDescriptor AnotherEntity = m_EntityContainer.CreateEntity<TransformComponent>();

        this->AddEntity(SomeEntity);
        this->AddEntity(AnotherEntity);
    }

    void TestScene::HandleEvent(const sf::Event& Event)
    {
    }

    void TestScene::Update(std::uint32_t DeltaTime)
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

    void TestScene::Render(sf::RenderWindow& Window)
    {
    }
} // namespace Tano