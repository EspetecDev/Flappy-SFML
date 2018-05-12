#include <iostream>
#include "Game.hpp"
#include "Definitions.hpp"

// switch to WinMain if it's configured for Subsystem::Windows
int WinMain() {
	
	Fuet::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Flappy Bird");

	return EXIT_SUCCESS;
}