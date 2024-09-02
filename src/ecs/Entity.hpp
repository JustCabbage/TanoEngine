#pragma once
#include <bitset>

namespace Tano
{
    using Entity = std::size_t;
    constexpr std::size_t MAX_COMPONENTS = 32;
    using ComponentMask = std::bitset<MAX_COMPONENTS>;

    struct EntityDescriptor
    {
        Entity entity;
        ComponentMask mask;

        bool operator==(const EntityDescriptor& Other) const
        {
            return entity == Other.entity;
        }
    };
} // namespace Tano