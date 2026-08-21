#include "Play.h"
namespace engPro {
	Play::Play(){
		ballsVector = new std::vector<Ball*>();
		ballQuantity = 20;
		playerShip = nullptr;
	}
	Play::~Play(){}
	void Play::OnEnter()
	{
		ballsVector = new std::vector<Ball*>();
		float curDeg = 0;
		for (int i = 0; i < ballQuantity; i++) {
			curDeg = (360 / ballQuantity) * i;
			//TraceLog(LOG_DEBUG, "grado: " + curDeg + ", curBall: " + i);
			Vector2 vel = { cos((curDeg * PI) / 180),-sin((curDeg * PI) / 180) };

			Ball* nBall = new Ball(Vector2{ (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 }, vel);
			ballsVector->push_back(nBall);
		}

		Listen("LoadScene");
		Listen("PlayerDie");

		playerShip = new Ship(Vector2{ (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 });
		entityManager.AddEntity(playerShip);

	}
	void Play::OnExit()
	{
		for (int i = ballQuantity -1; i >= 0; i--) {
			delete(ballsVector->at(i));
		}
		delete(ballsVector);
		entityManager.Clear();
	}
	void Play::Update()
	{
		for (int i = 0; i < ballQuantity; i++) {
			ballsVector->at(i)->Update();
		}

		entityManager.Update();

		if (IsKeyPressed(KEY_L)) 
			EventBus::GetInstance().Fire("LoadScene", { "LoadScene" });
		
		else if (IsKeyPressed(KEY_D))
			EventBus::GetInstance().Fire("PlayerDie", { "PlayerDie" });
	}
	void Play::Draw()
	{
		BeginDrawing();

		entityManager.Draw();

		ClearBackground(DARKGREEN);
		for (int i = 0; i < ballQuantity; i++) {
			ballsVector->at(i)->Draw();
		}
		EndDrawing();
	}
	void Play::OnEvent(EventData eData)
	{
		if (eData.type == "LoadScene")
			TraceLog(LOG_DEBUG, "Loading");
		else if(eData.type == "PlayerDie")
			TraceLog(LOG_DEBUG, "Muerte");

	}
}