#pragma once
#include <bitset>

namespace Tano
{
    constexpr std::size_t MAX_COMPONENTS = 32;
    constexpr std::size_t MAX_ENTITIES = 256;
    static std::size_t ComponentCount = 0;

    using Entity = std::size_t;
    using ComponentMask = std::bitset<MAX_COMPONENTS>;

    template <typename ComponentType>
    inline std::size_t GetComponentId()
    {
        static std::size_t ComponentId = ComponentCount++;
        return ComponentId;
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