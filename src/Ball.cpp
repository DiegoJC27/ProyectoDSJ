#include "Ball.h"

namespace engPro
{
	Ball::Ball(Vector2 iniPos, float curDeg) : Entity(iniPos, 20) {
		color = { (unsigned char)GetRandomValue(1,255),
			(unsigned char)GetRandomValue(1,255),
			(unsigned char)GetRandomValue(1,255),
			255 };
		velocity = { cos((curDeg * PI) / 180),-sin((curDeg * PI) / 180) };
		startPos = iniPos;
	}

	void Ball::Update()
	{
		position.x += velocity.x;
		position.y += velocity.y;
		if (position.x > GetScreenWidth() || position.x < 0)
			velocity.x *= -1;
		if (position.y > GetScreenHeight() || position.y < 0)
			velocity.y *= -1;

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
		EventBus::GetInstance().Fire("OnBallCollisioned");
	}
}
