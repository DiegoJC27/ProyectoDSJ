#include "Engine.h"

Engine::Engine() {
	ballsVector = new std::vector<Ball*>();
	ballQuantity = 100;
}

void Engine::Initialize()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	InitWindow(800, 600, "Hello Raylib");

	SearchAndSetResourceDir("resources");

	//Pruebas para calse

	float curDeg = 0;
	for (int i = 0; i < ballQuantity; i++) {
		curDeg = (360 / ballQuantity) * i;
		Vector2 vel = { cos((curDeg * PI) / 180),-sin((curDeg * PI) / 180) };

		Ball* nBall = new Ball(Vector2{ (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 }, vel);
		ballsVector->push_back(nBall);
	}
}
void Engine::Run()
{
	while (!WindowShouldClose())
	{
		Update();
		Draw();
	}
}
void Engine::ShutDown()
{
	CloseWindow();
}
void Engine::Update()
{
	for (int i = 0; i < ballQuantity; i++) {
		ballsVector->at(i)->Update();
	}
}
void Engine::Draw()
{
	BeginDrawing();
	ClearBackground(DARKGRAY);

	for (int i = 0; i < ballQuantity; i++) {
		ballsVector->at(i)->Draw();
	}

	EndDrawing();
}