/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "Engine.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main ()
{
	engPro::Engine engine;
	
	engine.Initialize();

	engine.Run();
	
	engine.ShutDown();

	return 0;
}
