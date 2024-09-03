#include "Entity.hpp"

namespace Tano
{
    class ECS
    {
    public:
        static EntityDescriptor CreateEntity();

        template <typename ComponentType>
        static std::uint32_t GetComponentId()
        {
            static std::uint32_t ComponentId = s_ComponentCount++;
            return ComponentId;
        }

        template <typename ComponentType>
        static void AddComponent(EntityDescriptor& Entity)
        {
            Entity.mask.set(GetComponentId<ComponentType>());
        }

        template <typename ComponentType>
        static bool HasComponent(const EntityDescriptor& Entity)
        {
            return Entity.mask.test(GetComponentId<ComponentType>());
        }

    public:
        static std::uint32_t s_EntityCount;
        static std::uint32_t s_ComponentCount;
    };
} // namespace Tano