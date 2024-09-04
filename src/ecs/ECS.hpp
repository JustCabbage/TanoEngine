#include "Entity.hpp"

namespace Tano
{
    class ECS
    {
    public:
        static EntityDescriptor CreateEntity();

    public:
        static std::uint32_t s_EntityCount;
        static std::uint32_t s_ComponentCount;
    };
} // namespace Tano