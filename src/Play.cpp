#include "Play.h"
namespace engPro {
	Play::Play(){
		ballsVector = new std::vector<Ball*>();
		ballQuantity = 100;

		float curDeg = 0;
		for (int i = 0; i < ballQuantity; i++) {
			curDeg = (360 / ballQuantity) * i;
			//TraceLog(LOG_DEBUG, "grado: " + curDeg + ", curBall: " + i);
			Vector2 vel = { cos((curDeg * PI) / 180),-sin((curDeg * PI) / 180) };

			Ball* nBall = new Ball(Vector2{ (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 }, vel);
			ballsVector->push_back(nBall);
		}
	}
	Play::~Play(){}
	void Play::OnEnter()
	{
	}
	void Play::OnExit()
	{
	}
	void Play::Update()
	{
		for (int i = 0; i < ballQuantity; i++) {
			ballsVector->at(i)->Update();
		}
	}
	void Play::Draw()
	{
		BeginDrawing();

		ClearBackground(DARKGREEN);
		for (int i = 0; i < ballQuantity; i++) {
			ballsVector->at(i)->Draw();
		}
		EndDrawing();
	}
}