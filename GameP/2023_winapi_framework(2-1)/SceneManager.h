#pragma once
class Scene;
class SceneManager
{
	SINGLE(SceneManager);
public:
	void RegisterScene(const wstring* sceneName, std::shared_ptr<Scene> scene);
	void LoadScene(const wstring& sceneName);
public:
	void Init();
	void Update();
	void Render(HDC dc);


public:
	const std::shared_ptr<Scene>& GetCurScene() const
	{
		return _curScene;
	}
private:
	std::shared_ptr<Scene> _curScene; //현재 씬;
	map<wstring, std::shared_ptr<Scene>> _scenesMap; //모든 씬을 Map으로 관리
};

