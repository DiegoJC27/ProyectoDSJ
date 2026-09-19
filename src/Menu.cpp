#include "Menu.h"
namespace engPro {
	Menu::Menu(): menuUI(nullptr){
		//bgm = ResourceManager::get().GetMusic("menuBGM.wav");
	}
	Menu::~Menu(){}
	void engPro::Menu::OnEnter()
	{
		//PlayMusicStream(bgm);
		Vector2	pos = { GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 - 50 };
		menuUI = new MenuUI(pos, 200, 50);							
	}
	void Menu::OnExit()
	{
		//StopMusicStream(bgm);
		delete(menuUI);
	}
	void Menu::Update()
	{
		//UpdateMusicStream(bgm);
	}
	void Menu::Draw()
	{
		BeginDrawing();

		ClearBackground(DARKBLUE);

		menuUI->Draw();
		
		EndDrawing();
	}
	
}