#pragma once

#include "Canvas.h"

namespace engPro {
	class MenuUI : public Canvas {
	public:
		MenuUI(Vector2 pos,  int wdt, int hgt) {
			position = pos;
			height = hgt;
			width = wdt;
			active = true;
		}
		void DrawGUI() override {	
			if (GuiButton(Rectangle{ position.x, position.y - 60, (float)width, (float)height }, "Play")) {

			}
			GuiButton(Rectangle{ position.x, position.y, (float)width, (float)height }, "Options");
			GuiButton(Rectangle{ position.x, position.y + 60, (float)width, (float)height }, "Exit");
		}
	};
}