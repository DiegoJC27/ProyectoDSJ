#pragma once
#include "Scene.h"
#include "EngGUI.h"
#include "ScoreManager.h"
#include "EventBus.h"
namespace engPro {
    class GameOver :
        public Scene, EventListener
    {
    private:
        GameOverUI* gameOverUI;
        public:
        GameOver();
        ~GameOver();
        void OnEnter() override;
        void OnExit() override;
        void Update() override;
		void Draw() override;

		void OnEvent(EventData eData) override;
    };
}
