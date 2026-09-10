#pragma once
#include "raylib.h"
#include <vector>
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

#include "SceneManager.h"
#include "ScoreManager.h"
#include <iostream>
#include <string>

namespace engPro {
	class Engine
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
		ScoreManager scoreManager;
		
	};
}