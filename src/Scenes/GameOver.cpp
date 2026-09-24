#include "GameOver.h"

namespace engPro
{
	GameOver::GameOver()
	{
		gameOverUI = nullptr;
	}

	GameOver::~GameOver()
	{
	}

	void GameOver::OnEnter()
	{
		Vector2	pos = { GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 - 50 };
		gameOverUI = new GameOverUI(pos, 200, 50);
	
	}

	void GameOver::OnExit()
	{
		delete(gameOverUI);
	}

	void GameOver::Update()
	{
	}

	void GameOver::Draw()
	{
		BeginDrawing();

		ClearBackground(DARKGRAY);

		gameOverUI->Draw();
		ScoreManager::Get().DrawScore();

		EndDrawing();
	}
	
	void GameOver::OnEvent(EventData eData)
	{
	}
}