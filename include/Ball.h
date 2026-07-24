#pragma once
#include "raylib.h"
#include <random>
class Ball
{
public:
	Ball(Vector2 iniPos, Vector2 iniVel);
	void Update();
	void Draw();
private:
	Vector2 position, velocity;
	Color color;
};

