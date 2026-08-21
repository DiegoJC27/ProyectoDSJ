#pragma once
#include "Entity.h"
namespace engPro
{
	class Bullet : public Entity
	{
	public:
		float speed{ 5.f };
		Vector2 direction{ 0.f, 0.f };
		Bullet(Vector2 iniPos, Vector2 dir);
		~Bullet() = default;

		void Update() override;
		void Draw() override;
	};
}
