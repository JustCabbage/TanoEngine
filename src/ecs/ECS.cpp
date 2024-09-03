#include "ECS.hpp"

namespace Tano
{
    std::uint32_t ECS::s_EntityCount = 0;
    std::uint32_t ECS::s_ComponentCount = 0;

    EntityDescriptor ECS::CreateEntity()
    {
        return {ECS::s_EntityCount++, ComponentMask()};
    }
} // namespace Tano