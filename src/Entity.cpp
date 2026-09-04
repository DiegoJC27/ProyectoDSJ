#include "Entity.h"
namespace engPro{
	Entity::Entity(Vector2 iniPos, float wdt)
	{
		position = iniPos;
		active = true;
		width = wdt;
		collider = new SphereCollider(position, width / 2);
	}
	void Entity::Draw()
	{
		if(texture.id == 0) {
			TraceLog(LOG_WARNING, "Entity texture is null. Cannot draw.");
			return;
		}
		DrawTexture(texture, position.x - width/2 , position.y - width/2 , WHITE);
		if (debugDrawCollision)
			collider->DebugDraw();
	}
	
	void Entity::SetPosition(Vector2 pos)
	{
		position = pos;
	}
	void Entity::SetPosition(float x, float y)
	{
		position.x = x;
		position.y = y;
	}
	void Entity::SetActive(bool _active)
	{
		active = _active;
	}
	bool Entity::IsActive()
	{
		return active;
	}
	void Entity::Collide()
	{
		SetActive(false);
	}
}