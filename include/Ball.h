#pragma once
#include "raylib.h"
#include "Entity.h"
#include <random>
#include "EventBus.h"

namespace engPro {

	class Ball : public Entity
	{

	public:
		Ball(Vector2 iniPos, float curDEG, float iniSpeed);
		void Update() override;
		void Draw() override;

		void Collide() override;

		void SetSpeed(float newSpeed);
	private:

		void SetDirection(float deg);
		Vector2 direction{ 0, 0 };
		float speed{ 0 };
		Vector2 startPos;
		Color color;
	};
}
