#pragma once
#include <SFML/Graphics.hpp>
#include <ecs/Entity.hpp>
#include <utils/Debug.hpp>
#include <vector>

namespace Tano
{
    class Scene
    {
    public:
        Scene(const std::string_view SceneId) : m_SceneId(SceneId)
        {
        }

    public:
        virtual void HandleEvent(const sf::Event& Event) = 0;
        virtual void Update(std::uint32_t DeltaTime) = 0;
        virtual void Render(sf::RenderWindow& Window) = 0;

    public:
        const std::string& GetSceneId() const;
        void AddEntity(const EntityDescriptor& Entity);
        void RemoveEntity(const EntityDescriptor& Entity);
        void ClearEntities();

    protected:
        std::string m_SceneId;
        std::vector<EntityDescriptor> m_Entities;
    };
} // namespace Tano