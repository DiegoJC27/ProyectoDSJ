#include "Entity.h"
namespace engPro{
	Entity::Entity(Vector2 iniPos)
	{
		position = iniPos;
		active = true;
	}
	void Entity::Draw()
	{
		if(texture.id == 0) {
			TraceLog(LOG_WARNING, "Entity texture is null. Cannot draw.");
			return;
		}
		DrawTextureEx(texture, position, 0.f, 1.f, WHITE);
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
}