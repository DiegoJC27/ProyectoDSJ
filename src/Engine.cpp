#include "Engine.h"
namespace engPro {
	Engine::Engine() {
	}

	void Engine::Initialize()
	{
		SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

		InitWindow(800, 600, "Hello Raylib");

		SearchAndSetResourceDir("resources");

		//Pruebas para calse
		sceneManager.ChangeScene(&menuScene);
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
		if (IsKeyPressed(KEY_M))
			sceneManager.ChangeScene(&menuScene);
		

		sceneManager.Update();
	}
	void Engine::Draw()
	{
		sceneManager.Draw();
	}
}