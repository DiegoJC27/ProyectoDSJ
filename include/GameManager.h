#pragma once
#include "EventBus.h"
#include "raylib.h"
#include "json.hpp"

using json = nlohmann::json;

namespace engPro
{
    class GameManager :
        public EventListener
    {
    public:
        static GameManager& Get()
        {
            static GameManager instance;
            return instance;
        }

        GameManager();
        ~GameManager();

        void DrawScore();
        void UpdateScore();
		void OnEvent(EventData eData) override;

		void ResetScore() { curScore = 0; }
        
    private:
        int curScore{ 0 };
		int highScore{ 0 };
        void SaveHighScore();
    };
}
