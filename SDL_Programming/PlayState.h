#pragma once
#include "Background.h"
#include "Player.h"
#include "GameState.h"
#include "Game.h"

class PlayState : public GameState
{

public:

	~PlayState() override {}

	bool OnEnter() override;
	GameState* Update() override;
	bool Render() override;
	void OnExit() override;

private:

	Background m_background;
	Player m_player;
	//All play variables declared here!
	//All main game play mechanics live in this class!!!!!
};