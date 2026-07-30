#include "Ball.h"

Ball::Ball(Vector2 iniPos, Vector2 iniVel) : position(iniPos), velocity(iniVel){
	color = { (unsigned char)GetRandomValue(1,255),
		(unsigned char) GetRandomValue(1,255),
		(unsigned char) GetRandomValue(1,255),
		255 };
}

void Ball::Update()
{
	position.x += velocity.x; 
	position.y += velocity.y;
	if (position.x > GetScreenWidth() || position.x < 0) 
		velocity.x *= -1;
	if (position.y > GetScreenHeight() || position.y < 0) 
velocity.y *= -1;
}

void Ball::Draw()
{
	DrawCircle(position.x, position.y, 10.f, color);
}
