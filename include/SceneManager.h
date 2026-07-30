#pragma once
#include "Scene.h"
namespace engPro {
	class SceneManager
	{
	public:
		void Update();
		void Draw();
		void ChangeScene(Scene* newScene);
	private:
		Scene* curScene = nullptr;
	};
}