#include "ScoreManager.h"

engPro::ScoreManager::ScoreManager()
{
	curScore = 0;
	highScore = 0;
	Listen("OnBallCollisioned");
}

engPro::ScoreManager::~ScoreManager()
{
}

void engPro::ScoreManager::DrawScore()
{
	DrawText(TextFormat("Highest Score: %i", highScore), 10, 10, 20, WHITE);
	DrawText(TextFormat("Current Score: %i", curScore), 10, 30, 20, WHITE);
}

void engPro::ScoreManager::UpdateScore()
{
	curScore += 100;
	if (curScore > highScore) {
		highScore = curScore;
	}
}

void engPro::ScoreManager::OnEvent(EventData eData)
{
	TraceLog(LOG_DEBUG, "entra en scoreManager");
	if(eData.type == "OnBallCollisioned") {
		UpdateScore();
	}
}
