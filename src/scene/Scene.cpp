#include "Scene.hpp"

namespace Tano
{
    const std::string& Scene::GetSceneId() const
    {
        return m_SceneId;
    }

    void Scene::AddEntity(const EntityDescriptor& Entity)
    {
        m_Entities.push_back(Entity);
        TANO_ASSERT(std::find(m_Entities.begin(), m_Entities.end(), Entity) != m_Entities.end(), "Scene::AddEntity() failed to add entity.");
    }
    
    void Scene::RemoveEntity(const EntityDescriptor& Entity)
    {
        m_Entities.erase(std::remove(m_Entities.begin(), m_Entities.end(), Entity), m_Entities.end());
        TANO_ASSERT(std::find(m_Entities.begin(), m_Entities.end(), Entity) == m_Entities.end(), "Scene::RemoveEntity() failed to remove entity.");
    }
    
    void Scene::ClearEntities()
    {
        m_Entities.clear();
        TANO_ASSERT(m_Entities.empty(), "Scene::ClearEntities() failed to clear all entities.");
    }
} // namespace Tano