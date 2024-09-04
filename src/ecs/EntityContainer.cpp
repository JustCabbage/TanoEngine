#include "EntityContainer.hpp"

namespace Tano
{

    void EntityContainer::AddEntity(const EntityDescriptor& Entity)
    {
        m_Entities.push_back(Entity);
        TANO_ASSERT(std::find(m_Entities.begin(), m_Entities.end(), Entity) != m_Entities.end(), "EntityContainer::AddEntity() failed to add entity.");
    }

    void EntityContainer::RemoveEntity(const EntityDescriptor& Entity)
    {
        m_Entities.erase(std::remove(m_Entities.begin(), m_Entities.end(), Entity), m_Entities.end());
        TANO_ASSERT(std::find(m_Entities.begin(), m_Entities.end(), Entity) == m_Entities.end(), "EntityContainer::RemoveEntity() failed to remove entity.");
    }

    std::vector<EntityDescriptor>& EntityContainer::GetEntities()
    {
        return m_Entities;
    }

    void EntityContainer::ClearEntities()
    {
        m_Entities.clear();
        TANO_ASSERT(m_Entities.empty(), "EntityContainer::ClearEntities() failed to clear all entities.");
    }
} // namespace Tano