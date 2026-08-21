#include "Bullet.h"

namespace engPro
{
	Bullet::Bullet(Vector2 iniPos, Vector2 dir)
		: Entity(iniPos), direction(dir) {
	}

	void Bullet::Update()
	{
		position.x += direction.x * speed;
		position.y += direction.y * speed;

		if(position.y < 0 || position.y > GetScreenHeight() || position.x < 0 || position.x > GetScreenWidth()) {
			SetActive(false);
		}
	}

	void Bullet::Draw()
	{
		DrawCircleV(position, 5.f, RED);
	}

}
