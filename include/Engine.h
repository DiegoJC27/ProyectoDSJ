#pragma once
#include "raylib.h"
#include <vector>
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include "Menu.h"
#include "Play.h"
#include "SceneManager.h"
#include "EventBus.h"
#include <iostream>
#include <string>

namespace engPro {
	class Engine : public EventListener
	{
	public:
		Engine();
		void Initialize();
		void Run();
		void ShutDown();
	private:
		void Update();
		void Draw();
		engPro::Menu menuScene;
		engPro::Play playScene;
		engPro::SceneManager sceneManager;

		void OnEvent(EventData eData) override;
		
	};
}