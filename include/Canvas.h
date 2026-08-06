#pragma once
#include "raygui.h"
#include "raylib.h"
namespace engPro {
	class Canvas
	{
	public:
		Canvas();
		~Canvas() = default;

		void Draw();

		void SetPosition(Vector2 pos);
		void SetActive(bool active);
		void SetSize(int wdt, int hgt);
	
		Vector2 position;
		int width;
		int height;
		bool active;
	protected:
		virtual void DrawGUI() = 0;

	};

}