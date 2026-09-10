#include "BallSpawner.h"

namespace engPro {
	/*engPro::BallSpawner::BallSpawner()
	{
	}*/

	void BallSpawner::Init() 
	{	
		ballSpawnPoint = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
		ballsVector = new std::vector<Ball*>();
		ballCurSpeed = ballInitialSpeed;
		for (int i = 0; i < inicialBallQuant; i++) {
			Ball* nBall = new Ball(ballSpawnPoint, curDeg, ballCurSpeed);
			curDeg += (360 / inicialBallQuant);
			ballsVector->push_back(nBall);
		}
		Listen("OnBallCollisioned");
	}
	void BallSpawner::TurnOff()
	{
		StopListening();
	}
	void BallSpawner::Update() {
		for (int i = 0; i < ballsVector->size(); i++) {
			ballsVector->at(i)->Update();
		}
	}
	void BallSpawner::OnBallCollison()
	{
		ballCurSpeed += plusBallSpeed;
		if (ballCurSpeed > ballMaxSpeed) 
			ballCurSpeed = ballMaxSpeed;

		for(int i = 0; i < ballsVector->size(); i++) {
			ballsVector->at(i)->SetSpeed(ballCurSpeed);
		}

		if(ballsVector->size() >= maxBallCount)
			return;
		Ball* nb = new Ball(ballSpawnPoint, curDeg + 5, ballCurSpeed);
		curDeg += (360 / inicialBallQuant);
		ballsVector->push_back(nb);
	}
	void BallSpawner::OnEvent(EventData data)
	{
		if (data.type == "OnBallCollisioned") {
		TraceLog(LOG_DEBUG, "entra a ala func");
			OnBallCollison();
		}
	}
	void BallSpawner::Draw() {
		for (int i = 0; i < ballsVector->size(); i++) {
			ballsVector->at(i)->Draw();
		}
	}
}