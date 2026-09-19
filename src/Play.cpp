#include "Play.h"
namespace engPro {
	Play::Play(){
		
		playerShip = nullptr;
		//bgm = ResourceManager::get().GetMusic("playBGM.wav");
	}
	Play::~Play(){}

	void Play::OnEnter()
	{
		ballSpawner.Init();
		//PlayMusicStream(bgm);

		Listen("PlayerDie");
		
		playerShip = new Ship(Vector2{ (float)GetScreenWidth() / 2, ((float)GetScreenHeight() / 2) + 150});
		entityManager.AddEntity(playerShip);
		ScoreManager::Get().ResetScore();

	}
	void Play::OnExit()
	{
		//StopMusicStream(bgm);
		entityManager.Clear();
		delete playerShip;
		playerShip = nullptr;
	}
	void Play::Update()
	{
		//UpdateMusicStream(bgm);

		entityManager.Update();
		ballSpawner.Update();
		CheckCollisions();
		
	}
	void Play::Draw()
	{
		BeginDrawing();

		entityManager.Draw();
		ballSpawner.Draw();
		ScoreManager::Get().DrawScore();
		ClearBackground(DARKGRAY);
		EndDrawing();
	}
	void Play::CheckCollisions()
	{
		for (int i = 0; i < ballSpawner.ballsVector->size(); i++) {
			if (playerShip->collider->CheckCollision(ballSpawner.ballsVector->at(i)->collider)) {
				EventBus::GetInstance().Fire("PlayerDie");
				return;
			}
			playerShip->CheckBullCollisions(ballSpawner.ballsVector->at(i));
		}
	}
	void Play::OnEvent(EventData eData)
	{
		if (eData.type == "PlayerDie")
			playerShip->PlayerDie();

	}
}