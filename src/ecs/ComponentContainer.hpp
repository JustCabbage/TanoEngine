#pragma once
#include <array>
#include <unordered_map>

#include "Entity.hpp"

namespace Tano
{
    class ComponentContainerBase
    {
    public:
        std::size_t GetComponentEntries() const
        {
            return m_ComponentEntries;
        }

    protected:
        std::size_t m_ComponentEntries = 0;
    };

    template <typename ComponentType>
    class ComponentContainer : public ComponentContainerBase
    {
    public:
        void AddEntityData(const Entity EntityId, const ComponentType Component)
        {
            const auto Index = m_ComponentEntries++;
            m_Components[Index] = Component;
            m_EntityToIndex.insert({EntityId, Index});
            m_IndexToEntity.insert({Index, EntityId});
        }

        ComponentType& GetEntityData(const Entity& Entity)
        {
            return m_Components[m_EntityToIndex.at(Entity)];
        }

    private:
        std::array<ComponentType, MAX_ENTITIES> m_Components = {};
        std::unordered_map<Entity, std::size_t> m_EntityToIndex = {};
        std::unordered_map<std::size_t, Entity> m_IndexToEntity = {};
    };
} // namespace Tano