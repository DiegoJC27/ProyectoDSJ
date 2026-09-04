#include "BallSpawner.h"

namespace engPro {
	/*engPro::BallSpawner::BallSpawner()
	{
	}*/

	void BallSpawner::Init() 
	{	
		ballSpawnPoint = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
		ballsVector = new std::vector<Ball*>();
		for (int i = 0; i < inicialBallQuant; i++) {
			Ball* nBall = new Ball(ballSpawnPoint, curDeg);
			curDeg += (360 / inicialBallQuant);
			ballsVector->push_back(nBall);
		}
		Listen("OnBallCollisioned");
	}
	void BallSpawner::Update() {
		for (int i = 0; i < ballsVector->size(); i++) {
			ballsVector->at(i)->Update();
		}
	}
	void BallSpawner::OnBallCollison()
	{
		TraceLog(LOG_DEBUG, "entra a ala func");
		Ball* nb = new Ball(ballSpawnPoint, curDeg + 5);
		curDeg += (360 / inicialBallQuant);
		ballsVector->push_back(nb);
	}
	void BallSpawner::OnEvent(EventData data)
	{
		if (data.name == "OnBallCollisioned") {
			OnBallCollison();
		}
	}
	void BallSpawner::Draw() {
		for (int i = 0; i < ballsVector->size(); i++) {
			ballsVector->at(i)->Draw();
		}
	}
}