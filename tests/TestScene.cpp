#include "TestScene.hpp"

namespace Tano
{
    TestScene::TestScene(const std::string_view SceneId) : Scene(SceneId)
    {
        EntityDescriptor SomeEntity = m_EntityContainer.CreateEntity<TransformComponent, CollideComponent>();
        EntityDescriptor AnotherEntity = m_EntityContainer.CreateEntity<TransformComponent>();

        m_EntityContainer.AddEntity(SomeEntity);
        m_EntityContainer.AddEntity(AnotherEntity);
    }

    void TestScene::HandleEvent(const sf::Event& Event)
    {
    }

    void TestScene::Update(std::uint32_t DeltaTime)
    {
        for (const auto& Entity : m_EntityContainer.GetEntities())
        {
            if (Entity.HasComponent<TransformComponent>())
            {
                auto& TransformContainer = m_EntityContainer.GetComponentContainer<TransformComponent>();
                auto& Transform = TransformContainer.GetEntityData(Entity.entity);

                // Do something with Transform component
            }

            if (Entity.HasComponent<CollideComponent>())
            {
                auto& CollideContainer = m_EntityContainer.GetComponentContainer<CollideComponent>();
                auto& Collide = CollideContainer.GetEntityData(Entity.entity);

                // Do something with Collide component
            }
        }
    }

    void TestScene::Render(sf::RenderWindow& Window)
    {
    }
} // namespace Tano