#include <iostream>
#include <SDL.h>
#include <stdlib.h>
#include <ctime>

#include "Background.h"
#include "Coin.h"
#include "Enemy.h"
#include "Input.h"
#include "Music.h"
#include "Player.h"
#include "Score.h"
#include "Screen.h"
#include "Sprite.h"
#include "Spell.h"
#include "Stone.h"
#include "Text.h"
#include "Vector2D.h"

//Global var
bool isGameRunning = true;
//int scoreInt = 0;

//Functions

//MAIN
int main(int argc, char* argv[])
{
	Screen screen;
	Input input;

	//only call once before any music objects are loaded
	Music::Initialize();
	Text::Initialize();

	//Sprite background;
	//srand(time(NULL));
	//std::srand(std::time(nullptr));

	if (!screen.Initialize("My game", 1280, 720))
	{
		return 0;
	}


	Background background(screen);

	Player player(screen);
	player.SetPosition(100, 200);
	player.SetAngle(0.0);
	player.SetSize(60, 100);
	player.SetVelocity(5);
	
	//Stone stone(screen);
	//stone.SetPosition(200, 200);
	//stone.SetAngle(0.0);
	//stone.SetSize(16, 16);
	//stone.SetVelocity(0);

	Coin goldcoin(screen);
	goldcoin.SetPosition(500, 500);
	goldcoin.SetSize(50, 50);
	goldcoin.SetAngle(0.0);
	
	Enemy enemy(screen);
	enemy.SetPosition(350, 350);
	enemy.SetSize(60, 96);
	enemy.SetVelocity(0);

	//===========================================

	Music music;

	music.Load("Assets/Music/background_music.mp3");
	music.Play(Music::PlayLoop::PLAY_ENDLESS);

	//===========================================

	Score* score = new Score;
	score->SetScore(0);

	//===========================================
	//MAIN GAME LOOP
	//===========================================
	while (isGameRunning)
	{

		screen.Clear();
		input.Update();

		if (input.IsWindowClosed())
		{
			isGameRunning = false;
		}
		if (input.GetKeyDown() == SDLK_ESCAPE )
		{
			isGameRunning = false;
		}

		/* 
		Could't find solution to use scoreto exit game.
		
		scoreInt = score->GetScore();
		if (scoreInt >= 10 || scoreInt < 10)
		{
			isGameRunning = false;
		}
		if (score->GetScore() >= 10 || score->GetScore() < 10)
		{
			isGameRunning = false;
		}
		*/
		//=======================================================================

		background.Update(input);
		background.Render(screen);
		
		//=======================================================================
		
		player.IsVisible(true);

		if (player.IsVisible())
		{
			player.Render(screen);
		}

		//=======================================================================
		
		//stone.Update(input);
		//stone.Render(screen);

		goldcoin.Update(input);
		goldcoin.Render(screen);

		enemy.Update(input);
		enemy.Render(screen);

		//=======================================================================
		//==============COLLISION TESTES AND REACTIONS HERE=======================
		//=======================================================================
		
		BoxCollider playerCollider = player.GetCollider();
		BoxCollider enemyCollider = enemy.GetCollider();
		BoxCollider coinCollider = goldcoin.GetCollider();
		//BoxCollider stoneCollider = stone.GetCollider();

		if (playerCollider.IsColliding(enemyCollider))
		{
			std::cout << "Enemy Collision!" << std::endl;
			enemy.Respawn(rand() % (1100 - enemy.GetSize().x), (rand() % (690 - enemy.GetSize().y)));
			score->SetScore(-1);
		}
		else
		{
			std::cout << "NO Collision!" << std::endl;
		}
		if (coinCollider.IsColliding(playerCollider))
		{
			std::cout << "Collision!" << std::endl;
			goldcoin.RespawnObject(rand() % (1100 - goldcoin.GetSize().x), (rand() % (690 - goldcoin.GetSize().y)));
			score->SetScore(1);
		}
		else
		{
			std::cout << "NO Collision!" << std::endl;
		}

		//=======================================================
		player.Update(input);

		//Vector2D MousePos = input.GetMousePosition();
		//Vector2D Result;

		//Result = MousePos.Subtract(player.GetPosition());

		//std::cout << "Mouse cursor at (" << Result.x << ", "<< Result.y << ")" << std::endl;
		std::cout << "Player position (" << player.GetPosition().x << ", " << player.GetPosition().y << ")" << std::endl;
		std::cout << "Coin position (" << goldcoin.GetPosition().x << ", " << goldcoin.GetPosition().y << ")" << std::endl;
		score->Render(screen);
		screen.Present();
	}

	delete score;

	//Only call this once after the game has ended

	Music::Shutdown();
	Text::Shutdown();

	background.~Background();
	screen.Shutdown();

	return 0;
}