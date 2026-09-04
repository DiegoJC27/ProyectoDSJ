#pragma once
#include "Entity.h"
#include "Bullet.h"
#include <vector>
#include <string>
namespace engPro
{
	class Ship :
		public Entity
	{
	private:
		float speed{ 1.0f };

		std::vector<Bullet*> bulletPool;				
		int iniPoolSize{ 10 };

		void Shoot();
		Bullet* GetBulletFromPool();

		Font mFont;
		Sound shootSound;

	public:
		Ship(Vector2 iniPos);
		~Ship();

		void Update() override;

		void Draw() override;

		void CheckBullCollisions(Entity* other);
	};
}