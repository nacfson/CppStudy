#include "pch.h"
#include "SceneManager.h"

void SceneManager::RegisterScene(const wstring* sceneName, std::shared_ptr<Scene> scene)
{
	_scenesMap.insert(_scenesMap.end(),{sceneName,scene});
}

void SceneManager::LoadScene(const wstring& sceneName)
{
	if (_curScene != nullptr)
	{
		_curScene->Release();
		_curScene = nullptr;
	}
	auto iter = _scenesMap.find(sceneName);
	if (iter != _scenesMap.end())
	{
		_curScene = iter->second;
		_curScene->Init();
	}
}

void SceneManager::Init()
{
	_curScene = nullptr;
}
void SceneManager::Update()
{
	_curScene->Update();
}

void SceneManager::Render(HDC dc)
{
	_curScene->Render(dc);
}
