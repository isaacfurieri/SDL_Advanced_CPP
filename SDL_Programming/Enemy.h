#pragma once

#include <iostream>

#include "BoxCollider.h"
#include "GameObject.h"
#include "Sprite.h"
#include "Sound.h"
#include "Spell.h"

class Enemy : public GameObject
{
public:
	enum State
	{
		Idle,
		Moving,
		Attacking,
		TakingHit,
		Death,
		TotalStates
	};

	Enemy();
	~Enemy();

	void ReceiveDamage(const int playerDamage);
	void SetVelocity(int velocity);
	void FlipToPlayer(Vector<int> playerPosition);
	void UpdateDirection(Vector<int> playerPosition); 
	void SetLooseHealth(int looseHealth);
	int GetDamage() const;
	int GetHealth() const;
	const BoxCollider& GetCollider() const;
	void SetState(const State& state);
	void Respawn(int posX, int posY);

	virtual void Update();
	virtual void Render();

private:

	State m_state{ State::Idle };
	Sprite m_images[State::TotalStates];       //containment - enemy has an image
	Sprite m_monsterHP, m_monsterRedHP;
	Sound m_dead;
	int m_healthPoints, m_maxHealthPoints, m_loseHealth, m_maxHealthBarSize;
	int m_damage;
	int m_velocity;
	Vector<int> m_direction;

	BoxCollider m_collider;
};

