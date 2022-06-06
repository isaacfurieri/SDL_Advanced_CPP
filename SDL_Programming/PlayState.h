#pragma once
#include <cstdlib>
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
	enum Enemies
	{
		FlyingEye, 
		Goblin, 
		Mushroom,
		Skeleton,
		Total
	};
	//All main game play mechanics live in this class!!!!!
	~PlayState() override {}

	float m_time = 0.0f;
	float m_timeMonster = 0.0f;
	float m_gameFinished = 0.0f;
	float m_respawnTimer = 0.0f;

	void SetRespawn(int posX, int posY);

	void Door(bool door);
	bool OnEnter() override;
	void OnExit() override;
	bool Render() override;
	
	GameState* Update() override;

private:

	//All play variables declared here!
	bool m_boolAnimation{ true }, m_respawnMob{ false };
	Vector<int> respawnPos;

	Background m_background;
	BoxCollider m_collider;
	//Enemy m_enemy;
	Enemy* m_enemies = nullptr;
	Player m_player;
	Score m_score;
	Sound m_doorOpening;
	Sprite m_doorAnimation, m_respawn;

};