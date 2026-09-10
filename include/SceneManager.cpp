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
		}
		
		curScene = newScene;
		
		curScene->OnEnter();
	}

	void SceneManager::OnEvent(EventData eData)
	{
		if (eData.type == "StartGame") {
			ChangeScene(&playScene);
		}
		else if( eData.type == "GameOver") {
			ChangeScene(&gameOverSceneScene);
		}
		else if (eData.type == "BackToMenu") {
			ChangeScene(&menuScene);
		}
		else if (eData.type == "ExitGame") {
			//WindowShouldClose();
		}
	}
	
}