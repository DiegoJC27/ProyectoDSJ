#pragma once
#include "raylib.h"
#include "raymath.h"

namespace engPro {
	class SphereCollider
	{
	private:
		Vector2 center;
		float radius;
	public:
		SphereCollider(Vector2 cent, float rad);
		~SphereCollider() = default;

		void SetPosition(Vector2 pos);
		void SetPosition(float px, float py);
		void DebugDraw();
		bool CheckCollision(SphereCollider* col);
	};
}
