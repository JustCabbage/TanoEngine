#pragma once
#include <SFML/Graphics.hpp>
#include <ecs/EntityContainer.hpp>
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
        void Shutdown()
        {
            m_EntityContainer.ClearEntities();
        }

    public:
        const std::string& GetSceneId() const;

    protected:
        std::string m_SceneId;
        EntityContainer m_EntityContainer;
    };
} // namespace Tano