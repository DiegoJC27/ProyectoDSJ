#include "Canvas.h"
#include "Entity.h"

namespace engPro
{
	Canvas::Canvas() : position({ 0, 0 }), width(0), height(0), active(false) {}

	void Canvas::Draw() {
		if (active) {
			DrawGUI();
		}
	}

	void Canvas::SetPosition(Vector2 pos)
	{
		position = pos;
	}

	void Canvas::SetActive(bool _active)
	{
		active = _active;
	}	

	void Canvas::SetSize(int wdt, int hgt)
	{
		width = wdt;
		height = hgt;
	}
}