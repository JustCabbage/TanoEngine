#pragma once
#include <SFML/Graphics.hpp>
#include <scene/Scene.hpp>

#include "WindowManager.hpp"

#define TANO_VERSION "0.0.1"

namespace Tano
{
    class Engine
    {
    public:
        Engine() = default;
        ~Engine() = default;

    public:
        bool CreateInstance();
        void Shutdown();

        template <typename SceneType>
        void CreateScene(const std::string& SceneId)
        {
            m_Scenes[SceneId] = std::make_unique<SceneType>(SceneId);
        }

        void SetActiveScene(const std::string& SceneId)
        {
            if (m_CurrentScene)
            {
                m_CurrentScene->ClearEntities();
            }

            auto it = m_Scenes.find(SceneId);
            if (it != m_Scenes.end())
            {
                m_CurrentScene = std::move(it->second);
            }
        }

        void UpdateScene(std::uint32_t DeltaTime)
        {
            if (!m_CurrentScene)
                return;

            m_CurrentScene->Update(DeltaTime);
        }

        Scene* GetCurrentScene()
        {
            return m_CurrentScene.get();
        }

        WindowManager& GetWindowManager()
        {
            return m_WindowManager;
        }

    private:
        std::unordered_map<std::string, std::unique_ptr<Scene>> m_Scenes;
        std::unique_ptr<Scene> m_CurrentScene;
        WindowManager m_WindowManager;
    };

} // namespace Tano
