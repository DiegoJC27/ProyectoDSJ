#pragma once
#include "EventBus.h"
#include "raylib.h"
namespace engPro
{
    class ScoreManager :
        public EventListener
    {
    public:
        static ScoreManager& Get()
        {
            static ScoreManager instance;
            return instance;
        }

        ScoreManager();
        ~ScoreManager();

        void DrawScore();
        void UpdateScore();
		void OnEvent(EventData eData) override;

		void ResetScore() { curScore = 0; }
    private:
        int curScore{ 0 };
		int highScore{ 0 };

    };
}
