#pragma once
#include "raylib.h"
#include <string>
namespace engPro
{
	class Entity
	{
	protected:
		Vector2 position;
		bool active;
		Texture2D texture;

	public:
		Entity(Vector2 iniPos);
		~Entity() = default;
		virtual void Draw();
		virtual void Update(){}

		void SetPosition(Vector2 pos);
		void SetPosition(float x, float y);

		void SetActive(bool active);
		bool IsActive();
	};

}
