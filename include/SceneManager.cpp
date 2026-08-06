#include "SceneManager.h"

namespace engPro {

	void SceneManager::Update() {
		if (curScene) {
			curScene->Update();
		}
	}
	void SceneManager::Draw() {
		if (curScene) {
			curScene->Draw();
		}
	}
	void SceneManager::ChangeScene(engPro::Scene* newScene)
	{
		if (!newScene) return;
		
		if (curScene) {
			curScene->OnExit();
			//delete(curScene);
		}
		
		curScene = newScene;
		
		curScene->OnEnter();
	}
}