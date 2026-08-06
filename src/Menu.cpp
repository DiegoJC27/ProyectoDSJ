#include "Menu.h"
namespace engPro {
	Menu::Menu(): menuUI(nullptr){}
	Menu::~Menu(){}
	void engPro::Menu::OnEnter()
	{		
		menuUI = new MenuUI({GetScreenWidth() / 2 -100, GetScreenHeight() / 2 -100},
							200, 50);
							
	}
	void Menu::OnExit()
	{
		delete(menuUI);
	}
	void Menu::Update()
	{
		if (IsKeyPressed(KEY_P))
			menuUI->SetActive(!menuUI->active);
			//menuUIsceneManager.ChangeScene(&playScene);
	}
	void Menu::Draw()
	{
		BeginDrawing();

		ClearBackground(DARKGRAY);

		DrawText("Menu(do)", 100, 100, 20, GOLD);

		menuUI->Draw();
		/*int* btnActive{ -1 };
		GuiMessageBox(Rectangle{ 10,50,60,20 }, "Ya valió", "O no", "corre", btnActive);*/

		EndDrawing();
	}
}