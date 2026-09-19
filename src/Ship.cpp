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
		shootSound = ResourceManager::get().GetSound("playerShot.wav");
		dieSound = ResourceManager::get().GetSound("playerDie.wav");

		maxPosConstrain = { (float)GetScreenWidth() - width, (float)GetScreenHeight() - width };

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
			if(position.y < 0) {
				position.y = 0;
			}	
		}
		if (IsKeyDown(KEY_S)) {
			position.y += speed;
			if(position.y > maxPosConstrain.y) {
				position.y = maxPosConstrain.y;
			}
		}
		if (IsKeyDown(KEY_A)) {
			position.x -= speed;
			if(position.x < 0) {
				position.x = 0;
			}
		}
		if (IsKeyDown(KEY_D)) {
			position.x += speed;
			if(position.x > maxPosConstrain.x) {
				position.x = maxPosConstrain.x;
			}
		}
		if (IsKeyPressed(KEY_SPACE)) {
			Shoot();
		}
		
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
	}
	void Ship::CheckBullCollisions(Entity* other)
	{
		for (int i = 0; i < bulletPool.size(); i++) {
			if (!bulletPool[i]->IsActive())
				continue;
			
			if (bulletPool[i]->collider->CheckCollision(other->collider)) {
				
				other->Collide();
				bulletPool[i]->Collide();
			}
		}
	}
	void Ship::PlayerDie()
	{
		PlaySound(dieSound);
		EventBus::GetInstance().Fire("GameOver", { "GameOver" });
	}
}