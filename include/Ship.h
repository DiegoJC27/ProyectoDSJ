#pragma once
#include "Entity.h"
#include "Bullet.h"
#include <vector>

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

	public:
		Ship(Vector2 iniPos);
		~Ship() = default;

		void Update() override;

		void Draw() override;
	};
}