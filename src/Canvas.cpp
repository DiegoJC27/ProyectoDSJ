#include "Canvas.h"

engPro::Canvas::Canvas() : position({ 0, 0 }), width(0), height(0), active(false) {}

void engPro::Canvas::Draw() {
	if(active) {
		DrawGUI();
	}
}

void engPro::Canvas::SetPosition(Vector2 pos)
{
	position = pos;
}

void engPro::Canvas::SetActive(bool _active)
{
	active = _active;
}

void engPro::Canvas::SetSize(int wdt, int hgt)
{
	width = wdt;
	height = hgt;
}
