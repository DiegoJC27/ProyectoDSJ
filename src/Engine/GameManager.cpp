#include "GameManager.h"
#include <fstream>

engPro::GameManager::GameManager()
{
	char* path = LoadFileText("../resources/json/highscore.json");
	
	if (path == nullptr)
	{
		TraceLog(LOG_WARNING, "No se pudo cargar highscore.json");
		highScore = 0;
	}
	else {
		try		{
			json data = json::parse(path);
			if (data.contains("highscore") && data["highscore"].is_number())
			{
				highScore = data["highscore"].get<int>();
			}
			else {
				TraceLog(LOG_WARNING, "no jalo");
				highScore = 0;
			}
		}
		catch (const std::exception& e)
		{
			TraceLog(LOG_ERROR, "Error parseando highscore.json: %s", e.what());
			highScore = 0;
		}
		UnloadFileText(path);
	}

	curScore = 0;
	Listen("OnBallCollisioned");
}

engPro::GameManager::~GameManager()
{
}

void engPro::GameManager::DrawScore()
{
	DrawText(TextFormat("Highest Score: %i", highScore), 10, 10, 20, WHITE);
	DrawText(TextFormat("Current Score: %i", curScore), 10, 30, 20, WHITE);
}

void engPro::GameManager::UpdateScore()
{
	curScore += 100;
	if (curScore > highScore) {
		highScore = curScore;
		SaveHighScore();
	}
}

void engPro::GameManager::OnEvent(EventData eData)
{
	if(eData.type == "OnBallCollisioned") {
		UpdateScore();
	}
}

void engPro::GameManager::SaveHighScore()
{
	json data;

	data["highscore"] = highScore;

	std::string jsonText = data.dump(4);

	SaveFileText(
		"../resources/json/highscore.json",
		jsonText.data()
	);
}
