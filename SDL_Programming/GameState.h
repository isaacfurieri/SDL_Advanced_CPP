#pragma once

#include "Background.h"
#include "Coin.h"
#include "Enemy.h"
#include "Input.h"
#include "Music.h"
#include "Player.h"
#include "Score.h"
#include "Screen.h"
#include "Text.h"

//This is an ABC class because we have at least 1 puure virtual function (= 0)
//You cannot instantiate this class!

class GameState
{

public:

	//GameState(Screen& screen);
	
	virtual ~GameState() = 0 {}

	virtual bool OnEnter() = 0;       //Load assets in this function
	virtual GameState* Update() = 0;  //Here we update all of our game mechanics
	virtual bool Render() = 0;        //Here we draw all of our scene's game objects
	virtual void OnExit() = 0;        //Unload assets in this function

protected:

	//Screen& m_screen;

};