#pragma once
#include <bitset>

// TODO: Rewrite this to properly integrate into the codebase

namespace Tano
{
    constexpr std::size_t MAX_COMPONENTS = 32;
    using Entity = std::size_t;
    using ComponentMask = std::bitset<MAX_COMPONENTS>;

    struct EntityDescriptor;

    static std::uint32_t s_EntityCount = 0;
    static std::uint32_t s_ComponentCount = 0;

    template <typename ComponentType>
    inline std::uint32_t GetComponentId()
    {
        static std::uint32_t ComponentId = s_ComponentCount++;
        return ComponentId;
    }

    template <typename Entity, typename ComponentType>
    void AddComponentProxy(Entity& entity)
    {
        entity.template AddComponent<ComponentType>();
    }

    template <typename... ComponentTypes>
    EntityDescriptor CreateEntity()
    {
        EntityDescriptor entity{s_EntityCount++, ComponentMask()};
        (AddComponentProxy<EntityDescriptor, ComponentTypes>(entity), ...);
        return entity;
    }

    struct EntityDescriptor
    {
        Entity entity;
        ComponentMask mask;

        bool operator==(const EntityDescriptor& Other) const
        {
            return entity == Other.entity;
        }

        template <typename ComponentType>
        void AddComponent()
        {
            mask.set(GetComponentId<ComponentType>());
        }

        template <typename ComponentType>
        bool HasComponent()
        {
            return mask.test(GetComponentId<ComponentType>());
        }
    };
} // namespace Tano