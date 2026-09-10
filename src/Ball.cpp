#include "Ball.h"

namespace engPro
{
	Ball::Ball(Vector2 iniPos, float curDeg, float iniSpeed) : Entity(iniPos, 20) {
		color = { (unsigned char)GetRandomValue(1,255),
			(unsigned char)GetRandomValue(1,255),
			(unsigned char)GetRandomValue(1,255),
			255 };
		SetDirection(curDeg);
		SetSpeed(iniSpeed);
		startPos = iniPos;
	}

	void Ball::Update()
	{
		position.x += direction.x * speed;
		position.y += direction.y * speed;
		if (position.x > GetScreenWidth() || position.x < 0)
			direction.x *= -1;
		if (position.y > GetScreenHeight() || position.y < 0)
			direction.y *= -1;

		collider->SetPosition(position);
	}

	void Ball::Draw()
	{
		DrawCircle(position.x, position.y, 10.f, color);
		if (debugDrawCollision)
			collider->DebugDraw();
	}
	void Ball::Collide()
	{
		position = startPos;
		collider->SetPosition(position);
		SetDirection(GetRandomValue(0, 360));
		EventBus::GetInstance().Fire("OnBallCollisioned");
	}
	void Ball::SetSpeed(float newSpeed)
	{
		speed = newSpeed;
	}
	void Ball::SetDirection(float deg)
	{
		direction = { cos((deg * PI) / 180),-sin((deg * PI) / 180) };
	}
}
