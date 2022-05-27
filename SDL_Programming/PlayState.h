#pragma once

#include "Background.h"
#include "Enemy.h"
#include "Sprite.h"
#include "BoxCollider.h"
#include "EndState.h"
#include "MenuState.h"
#include "GameState.h"
#include "Game.h"
#include "Player.h"
#include "Score.h"

class PlayState : public GameState
{

public:
	//All main game play mechanics live in this class!!!!!
	~PlayState() override {}

	float m_time = 0;
	float m_timeMonster = 0;
	float m_gameFinished = 0.0f;

	void Door(bool door);
	bool OnEnter() override;
	void OnExit() override;
	bool Render() override;
	
	GameState* Update() override;

private:

	//All play variables declared here!
	bool m_boolAnimation{ true };

	Background m_background;
	BoxCollider m_collider;
	Enemy m_enemy;
	Player m_player;
	Score m_score;
	Sound m_doorOpening;
	Sprite m_doorAnimation;
};