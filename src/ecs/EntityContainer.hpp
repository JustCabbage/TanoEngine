#pragma once
#include <array>
#include <cstdint>
#include <memory>
#include <utils/Debug.hpp>
#include <vector>

#include "ComponentContainer.hpp"
#include "Entity.hpp"

namespace Tano
{
    class EntityContainer
    {
    public:
        template <typename... ComponentTypes>
        EntityDescriptor CreateEntity()
        {
            TANO_ASSERT(m_EntityCount < MAX_ENTITIES, "Reached entity limit");
            EntityDescriptor entity{m_EntityCount++, ComponentMask()};
            (entity.AddComponent<ComponentTypes>(), ...);
            (GetComponentContainer<ComponentTypes>().AddEntityData(entity.entity, ComponentTypes()), ...);
            return entity;
        }

        template <typename ComponentType>
        ComponentContainer<ComponentType>& GetComponentContainer()
        {
            if (!m_ComponentContainers[GetComponentId<ComponentType>()])
            {
                m_ComponentContainers[GetComponentId<ComponentType>()] = std::make_unique<ComponentContainer<ComponentType>>();
            }

            return *static_cast<ComponentContainer<ComponentType>*>(m_ComponentContainers[GetComponentId<ComponentType>()].get());
        }

        void AddEntity(const EntityDescriptor& Entity);
        void RemoveEntity(const EntityDescriptor& Entity);
        std::vector<EntityDescriptor>& GetEntities();
        void ClearEntities();

    private:
        std::uint32_t m_EntityCount = 0;
        std::vector<EntityDescriptor> m_Entities = {};
        std::array<std::unique_ptr<ComponentContainerBase>, MAX_COMPONENTS> m_ComponentContainers = {};
    };
} // namespace Tano