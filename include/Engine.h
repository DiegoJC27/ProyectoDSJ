#pragma once
#include "raylib.h"
#include <vector>
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include "Ball.h"


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
	std::vector<Ball*>* ballsVector;
	int ballQuantity;
};