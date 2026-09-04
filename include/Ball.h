#pragma once
#include "raylib.h"
#include "Entity.h"
#include <random>
#include "EventBus.h"

namespace engPro {

	class Ball : public Entity
	{

	public:
		Ball(Vector2 iniPos, float curDEG);
		void Update() override;
		void Draw() override;

		void Collide() override;
	private:
		Vector2 velocity;
		Vector2 startPos;
		Color color;
	};
}
