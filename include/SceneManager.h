#pragma once
#include "Menu.h"
#include "GameOver.h"
#include "Play.h"
#include "EventBus.h"
namespace engPro {
	class SceneManager: public EventListener
	{
	public:
		SceneManager() {
			Listen("StartGame");
			Listen("GameOver");
			Listen("BackToMenu");
			Listen("ExitGame");
		}

		void Update();
		void Draw();
		void ChangeScene(Scene* newScene);

		void OnEvent(EventData eData) override;
		
		Menu menuScene;
		Play playScene;
		GameOver gameOverSceneScene;

	private:


		Scene* curScene = nullptr;
	};
}