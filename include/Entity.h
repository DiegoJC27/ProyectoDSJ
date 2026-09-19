#pragma once
#include "raylib.h"
#include <string>
#include "ResourceManager.h"
#include "SphereCollider.h"

namespace engPro
{
	class Entity
	{
	protected:
		Vector2 position;
		bool active;
		bool debugDrawCollision{ true };
		float width;
		Texture2D texture;

	public:
		Entity(Vector2 iniPos, float width);
		~Entity() = default;
		virtual void Draw();
		virtual void Update(){}

		void SetPosition(Vector2 pos);
		void SetPosition(float x, float y);

		void SetActive(bool active);
		bool IsActive();
		SphereCollider* collider;

		virtual void Collide();
	};

}
