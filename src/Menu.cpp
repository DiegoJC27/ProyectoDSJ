#include "Menu.h"
namespace engPro {
	Menu::Menu(){
		
	}
	Menu::~Menu(){}
	void engPro::Menu::OnEnter()
	{		
		
	}
	void Menu::OnExit()
	{
	}
	void Menu::Update()
	{
		
	}
	void Menu::Draw()
	{
		BeginDrawing();

		ClearBackground(DARKGRAY);

		DrawText("Menu(do)", 100, 100, 20, GOLD);

		EndDrawing();
	}
}