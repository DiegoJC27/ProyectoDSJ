#pragma once

#include "Canvas.h"
#include "EventBus.h"

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
			//GuiLabel(Rectangle{ position.x, position.y - 60, (float)width, (float)height }, "Wacky Asteroids 2");
			DrawText("Wacky Asteroids 2", position.x - 50, position.y -150, 32, GOLD);
			if (GuiButton(Rectangle{ position.x, position.y - 60, (float)width, (float)height }, "Play")) {
				EventBus::GetInstance().Fire("StartGame", { "StartGame" });
			}
			
			GuiButton(Rectangle{ position.x, position.y, (float)width, (float)height }, "Options");
			
			if (GuiButton(Rectangle{ position.x, position.y + 60, (float)width, (float)height }, "Exit")) {
				EventBus::GetInstance().Fire("ExitGame", { "ExitGame" });
			}
		}
	};

	class GameOverUI : public Canvas {
	public:
		GameOverUI(Vector2 pos, int wdt, int hgt) {
			position = pos;
			height = hgt;
			width = wdt;
			active = true;
		}

		void DrawGUI() override {
			DrawText("Game Over", position.x - 50, position.y - 150, 32, RED);
			if (GuiButton(Rectangle{ position.x, position.y, (float)width, (float)height }, "Back to menu")) {
				TraceLog(LOG_DEBUG, "Back");
				EventBus::GetInstance().Fire("BackToMenu", { "BackToMenu" });
			}
			
			if (GuiButton(Rectangle{ position.x, position.y + 60, (float)width, (float)height }, "Exit")) {
				TraceLog(LOG_DEBUG, "Exit");
				EventBus::GetInstance().Fire("ExitGame", { "ExitGame" });
			}
		}

	};
}