#include "Menu.h"
namespace engPro {
	Menu::Menu(): menuUI(nullptr){}
	Menu::~Menu(){}
	void engPro::Menu::OnEnter()
	{
		Vector2	pos = { GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 - 50 };
		menuUI = new MenuUI(pos, 200, 50);							
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

		ClearBackground(DARKBLUE);

		//DrawText("Menu(do)", 100, 100, 20, GOLD);

		menuUI->Draw();
		
		EndDrawing();
	}
	
}