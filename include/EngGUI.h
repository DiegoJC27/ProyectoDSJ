#pragma once

#include "Canvas.h"
#include "EventBus.h"

namespace engPro {
	class MenuUI : public Canvas {
	public:
		MenuUI(Vector2 pos, int wdt, int hgt) {
			position = pos;
			height = hgt;
			width = wdt;
			active = true;
			showTutorial = false;
		}

		bool showTutorial{ false };
		std::string tutorialText1 = "DESTROY ASTEROIDS TO GAIN POINTS";
		std::string tutorialText2 = "IF AN ASTEROID HITS YOU, YOU LOSE";
		std::string tutorialText3 = "PRESS [W,A,S,D] TO MOVE";
		std::string tutorialText4 = "PRESS [SPACE] TO SHOOT";
	
		void DrawGUI() override {	
			//GuiLabel(Rectangle{ position.x, position.y - 60, (float)width, (float)height }, "Wacky Asteroids 2");
			DrawText("Wacky Asteroids 2", position.x - 50, position.y -150, 32, GOLD);
			if (!showTutorial) {
				if (GuiButton(Rectangle{ position.x, position.y - 60, (float)width, (float)height }, "Play")) {
					EventBus::GetInstance().Fire("StartGame", { "StartGame" });
				}

				if (GuiButton(Rectangle{ position.x, position.y, (float)width, (float)height }, "Options")) {
					showTutorial = true;
				}

				if (GuiButton(Rectangle{ position.x, position.y + 60, (float)width, (float)height }, "Exit")) {
					EventBus::GetInstance().Fire("ExitGame", { "ExitGame" });
				}
			}

			else  {
				DrawText(tutorialText1.c_str(), position.x-120, position.y - 30,  24, RAYWHITE);
				DrawText(tutorialText2.c_str(), position.x-120, position.y + 20, 24, RAYWHITE);
				DrawText(tutorialText3.c_str(), position.x-120, position.y + 70, 24, RAYWHITE);
				DrawText(tutorialText4.c_str(), position.x-120, position.y + 120, 24, RAYWHITE);
				if (GuiButton(Rectangle{ position.x, position.y + 200, (float)width, (float)height }, "Play")) {
					EventBus::GetInstance().Fire("StartGame", { "StartGame" });
				}
				if (GuiButton(Rectangle{ position.x, position.y + 260, (float)width, (float)height }, "Back")) {
					showTutorial = false;
				}
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