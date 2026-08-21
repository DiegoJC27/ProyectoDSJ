#include "Ship.h"
namespace engPro
{
	void Ship::Shoot()
	{
		Bullet* bullet = GetBulletFromPool();
		if (bullet != nullptr) {
			bullet->SetPosition(position);
			bullet->SetActive(true);
		}
		else {
			bullet = new Bullet(position, Vector2{ 0.f, -1.f });
			bulletPool.push_back(bullet);
		}
	}

	Bullet* Ship::GetBulletFromPool()
	{
		for(int i = 0; i < bulletPool.size(); i++)
		{
			if (!bulletPool[i]->IsActive()) {
				return bulletPool[i];
			}
		}
		return nullptr;
	}

	Ship::Ship(Vector2 iniPos)
		: Entity(iniPos)
	{
		texture = LoadTexture("PlayerShip.png");

		for(int i = 0; i < iniPoolSize; i++) {
			Bullet* newBullet = new Bullet(position, Vector2{ 0.f, -1.f });
			newBullet->SetActive(false);
			bulletPool.push_back(newBullet);
		}
	}

	void Ship::Update()
	{
		if (IsKeyDown(KEY_W)) {
			position.y -= speed;
		}
		if (IsKeyDown(KEY_S)) {
			position.y += speed;
		}
		if (IsKeyDown(KEY_A)) {
			position.x -= speed;
		}
		if (IsKeyDown(KEY_D)) {
			position.x += speed;
		}
		if (IsKeyDown(KEY_SPACE)) {
			Shoot();
		}
		for (int i = 0; i < bulletPool.size(); i++)
		{
			if(bulletPool[i]->IsActive()) {
				bulletPool[i]->Update();
			}
		}
	}
	void Ship::Draw()
	{
		Entity::Draw();
		for (int i = 0; i < bulletPool.size(); i++)
		{
			if(bulletPool[i]->IsActive()) {
				bulletPool[i]->Draw();
			}
		}
	}
}