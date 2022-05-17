#pragma once
#include "Background.h"
#include "Enemy.h"
#include "Player.h"
#include "Sprite.h"
#include "BoxCollider.h"
#include "EndState.h"
#include "MenuState.h"
#include "GameState.h"
#include "Game.h"

class PlayState : public GameState
{

public:

	~PlayState() override {}

	float m_time = 0;
	float m_timeMonster = 0;
	float m_gameFinished = 0.0f;
	void Door(bool door);
	bool OnEnter() override;
	GameState* Update() override;
	bool Render() override;
	void OnExit() override;

private:

	bool m_boolAnimation{ true };

	BoxCollider m_collider;
	Background m_background;
	Player m_player;
	Enemy m_enemy;
	Sprite m_doorAnimation;
	Sound m_doorOpening;
	//All play variables declared here!
	//All main game play mechanics live in this class!!!!!
};