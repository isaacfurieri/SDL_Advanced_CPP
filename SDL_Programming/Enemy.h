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

	Enemy(const std::string& enemyName);
	~Enemy();

	int GetHealth() const;
	int GetDamage() const;

	void FlipToPlayer(Vector<int> playerPosition);
	void ReceiveDamage(const int playerDamage);
	void Respawn(int posX, int posY);
	void SetLooseHealth(int looseHealth);
	void SetDamage(int damage);
	void SetState(const State& state);
	void SetVelocity(int velocity);
	void UpdateDirection(Vector<int> playerPosition); 
	
	Sprite GetImages();
	Enemy::State GetState();

	const BoxCollider& GetCollider() const;

	virtual void Update();
	virtual void Render();

private:

	int m_healthPoints, m_maxHealthPoints, m_loseHealth;
	int m_damage;
	int m_velocity;

	BoxCollider m_collider;
	State m_state{ State::Moving };
	Sprite m_images[State::TotalStates];       //containment - enemy has an image
	Sprite m_monsterHP, m_monsterRedHP, m_respawn;
	Sound m_dead;

	Vector<int> m_direction;

};

