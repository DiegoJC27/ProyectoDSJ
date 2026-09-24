#include "Play.h"
namespace engPro {
	Play::Play(){
		ballsVector = nullptr;
		bulletPool = nullptr;
		playerShip = nullptr;
	}
	Play::~Play(){}

	void Play::OnEnter()
	{
		bgm = ResourceManager::get().GetMusic("playBGM.wav");
		PlayMusicStream(bgm);

		Listen("PlayerDie");
		Listen("Shoot");

		playerShip = new Ship(Vector2{ (float)GetScreenWidth() / 2, ((float)GetScreenHeight() / 2) + 150 });
		entityManager.AddEntity(playerShip);
		ScoreManager::Get().ResetScore();

		//InitiBulPool
		bulletPool = new std::vector<Bullet*>();
		for (int i = 0; i < iniPoolSize; i++) {
			Bullet* newBullet = new Bullet(playerShip->position, Vector2{ 0.f, -1.f });
			newBullet->SetActive(false);
			bulletPool->push_back(newBullet);
			entityManager.AddEntity(newBullet);
		}

		//InitiBallsPool
		ballSpawnPoint = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
		ballsVector = new std::vector<Ball*>();
		ballCurSpeed = ballInitialSpeed;
		for (int i = 0; i < inicialBallQuant; i++) {
			Ball* nBall = new Ball(ballSpawnPoint, curDeg, ballCurSpeed);
			curDeg += (360 / inicialBallQuant);
			ballsVector->push_back(nBall);
			entityManager.AddEntity(nBall);
		}
	}
	void Play::OnExit()
	{
		StopListening();
		StopMusicStream(bgm);
		delete playerShip;
		playerShip = nullptr;

		for (int i = 0; i < bulletPool->size(); i++) {
			delete bulletPool->at(i);
		}
		bulletPool->clear();
		delete bulletPool;
		bulletPool = nullptr;

		for (int i = 0; i < ballsVector->size(); i++) {
			delete ballsVector->at(i);
		}
		ballsVector->clear();
		delete ballsVector;
		ballsVector = nullptr;

		entityManager.Clear();
	}
	void Play::Update()
	{
		UpdateMusicStream(bgm);

		entityManager.Update();
		CheckCollisions();
		
	}
	void Play::Draw()
	{
		BeginDrawing();
		
		ClearBackground(BLACK);

		entityManager.Draw();
		ScoreManager::Get().DrawScore();
		EndDrawing();
	}
	void Play::CheckCollisions()
	{
		for (int i = 0; i < ballsVector->size(); i++) {
			if (playerShip->collider->CheckCollision(ballsVector->at(i)->collider)) {
				EventBus::GetInstance().Fire("PlayerDie");
				return;
			}
			for (int j = 0; j < bulletPool->size(); j++) {
				if (!bulletPool->at(j)->IsActive()) {
					continue;
				}
				if (bulletPool->at(j)->collider->CheckCollision(ballsVector->at(i)->collider)) {
					bulletPool->at(j)->SetActive(false);
					ballsVector->at(i)->SetPosition(ballSpawnPoint);
					OnBallCollison();
				}
			}
		}
	}
	void Play::OnEvent(EventData eData)
	{
		if (eData.type == "PlayerDie")
			playerShip->PlayerDie();
		else if (eData.type == "Shoot") {
			Shoot();
		}
	}

	//Bullets
	void Play::Shoot()
	{
		Bullet* bullet = GetBulletFromPool();
		if (bullet != nullptr) {
			bullet->SetPosition(playerShip->position);
			bullet->SetActive(true);
		}
		else {
			bullet = new Bullet(playerShip->position, Vector2{ 0.f, -1.f });
			bulletPool->push_back(bullet);
			entityManager.AddEntity(bullet);
		}

	}

	Bullet* Play::GetBulletFromPool()
	{
		for (int i = 0; i < bulletPool->size(); i++)
		{
			if (!bulletPool->at(i)->IsActive()) {
				return bulletPool->at(i);
			}
		}
		return nullptr;
	}

	//Asteroids
	void Play::OnBallCollison()
	{
		ScoreManager::Get().UpdateScore();

		ballCurSpeed += plusBallSpeed;
		if (ballCurSpeed > ballMaxSpeed)
			ballCurSpeed = ballMaxSpeed;

		for (int i = 0; i < ballsVector->size(); i++) {
			ballsVector->at(i)->SetSpeed(ballCurSpeed);
		}

		if (ballsVector->size() >= maxBallCount)
			return;

		Ball* nb = new Ball(ballSpawnPoint, curDeg + 5, ballCurSpeed);
		curDeg += (360 / inicialBallQuant);
		ballsVector->push_back(nb);
		entityManager.AddEntity(nb);
	}
}