#include "Engine.h"
namespace engPro {
	Engine::Engine() {
	}

	void Engine::Initialize()
	{
		SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

		InitWindow(800, 600, "Hello Raylib");

		SearchAndSetResourceDir("resources");

		InitAudioDevice();

		SetTraceLogLevel(LOG_DEBUG);

		Listen("ExitGame");

		sceneManager.ChangeScene(&sceneManager.menuScene);
	}
	void Engine::Run()
	{
		while (!WindowShouldClose() && !shouldCloseWindow)
		{
			Update();
			Draw();
		}
	}
	void Engine::ShutDown()
	{
		StopListening();
		CloseWindow();
	}
	void Engine::Update()
	{	

		sceneManager.Update();
	}
	void Engine::Draw()
	{
		sceneManager.Draw();
	}

	void Engine::OnEvent(EventData event)
	{
		if (event.type == "ExitGame") {
			shouldCloseWindow = true;
		}
	}
	
}