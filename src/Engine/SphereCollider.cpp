#include "SphereCollider.h"
namespace engPro {
	SphereCollider::SphereCollider(Vector2 cent, float rad) : center(cent), radius(rad)
	{
	}
	void SphereCollider::DebugDraw()
	{
		DrawCircleLines(center.x, center.y, radius, RED);
	}
	void SphereCollider::SetPosition(Vector2 pos) 
	{
		center = pos;
	}
	void SphereCollider::SetPosition(float px, float py) 
	{
		center.x = px;
		center.y = py;
	}
	bool SphereCollider::CheckCollision(SphereCollider* col)
	{
		return (Vector2Distance(col->center, center) - radius - col->radius) <= 0;
	}
}