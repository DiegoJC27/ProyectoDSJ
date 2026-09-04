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

		PlaySound(shootSound);
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
		: Entity(iniPos, 15.f)
	{
		texture = ResourceManager::get().GetTexture("PlayerShip.png");
		mFont = ResourceManager::get().GetFont("Sunset Palm - Script Trial.otf");
		shootSound = ResourceManager::get().GetSound("rocket-launcher.wav");

		for(int i = 0; i < iniPoolSize; i++) {
			Bullet* newBullet = new Bullet(position, Vector2{ 0.f, -1.f });
			newBullet->SetActive(false);
			bulletPool.push_back(newBullet);
		}
	}

	Ship::~Ship()
	{
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
		if (IsKeyPressed(KEY_SPACE)) {
			Shoot();
		}
		//collider->SetPosition(position.x + (width / 2), position.y - (width / 2));
		collider->SetPosition(position);
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

		std::string poolSize = std::to_string(bulletPool.size());
		DrawTextEx(mFont, poolSize.c_str(), {position.x, position.y + 50.f}, 24, 5, RAYWHITE);
	}
	void Ship::CheckBullCollisions(Entity* other)
	{
		for (int i = 0; i < bulletPool.size(); i++) {
			if (!bulletPool[i]->IsActive())
				continue;
			
			if (bulletPool[i]->collider->CheckCollision(other->collider)) {
				TraceLog(LOG_DEBUG, "bala coll");
				other->Collide();
				bulletPool[i]->Collide();
			}
		}
	}
}