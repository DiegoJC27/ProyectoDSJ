#pragma once
#include "raylib.h"
#include <vector>
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

#include "SceneManager.h"
#include "GameManager.h"
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
		
		SceneManager sceneManager;
		bool shouldCloseWindow{ false };
		void OnEvent(EventData event) override;
	};
}