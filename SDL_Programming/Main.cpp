#include <iostream>
#include <SDL.h>
#include <stdlib.h>

#include "Game.h"
#include "GameState.h"
#include "MenuState.h"
#include "PlayState.h"

//MAIN
int main(int argc, char* argv[])
{
	std::unique_ptr<Game> game = std::make_unique<Game>();

	if (game->Initialize())
	{
		game->Run(new MenuState);
		game->Shutdown();
	}

	return 0;
}