#pragma once
#include "Entity.hpp"

namespace Tano
{
    class EntityContainer
    {
    public:
        template <typename... ComponentTypes>
        EntityDescriptor CreateEntity()
        {
            EntityDescriptor entity{m_EntityCount++, ComponentMask()};
            (entity.AddComponent<ComponentTypes>(), ...);
            return entity;
        }

    public:
        std::uint32_t m_EntityCount = 0;
    };
} // namespace Tano