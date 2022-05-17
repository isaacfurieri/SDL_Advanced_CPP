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

	int GetHealth() const;
	int GetDamage() const;

	void FlipToPlayer(Vector<int> playerPosition);
	void ReceiveDamage(const int playerDamage);
	void Respawn(int posX, int posY);
	void SetLooseHealth(int looseHealth);
	void SetState(const State& state);
	void SetVelocity(int velocity);
	void UpdateDirection(Vector<int> playerPosition); 
	
	Sprite GetImages();
	const BoxCollider& GetCollider() const;

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

