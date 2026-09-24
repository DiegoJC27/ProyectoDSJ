#include "Ball.h"

namespace engPro
{
	Ball::Ball(Vector2 iniPos, float curDeg, float iniSpeed) : Entity(iniPos, 20) {
		texture = ResourceManager::get().GetTexture("Asteroide.png");
		destroyedSound = ResourceManager::get().GetSound("asteroidDestroy.wav");
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
		if (texture.id == 0) {
			TraceLog(LOG_WARNING, "Ball texture is null. Cannot draw.");
			return;
		}

		DrawTextureEx(texture, { position.x - width / 2, position.y - width / 2 }, 0.f, 0.01f, WHITE);

		if (debugDrawCollision)
			collider->DebugDraw();
	}
	void Ball::Collide()
	{
		position = startPos;
		PlaySound(destroyedSound);
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
