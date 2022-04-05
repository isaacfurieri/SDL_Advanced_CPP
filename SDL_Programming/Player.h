#pragma once
#include <iostream>
#include <deque>
#include "BoxCollider.h"
#include "Game.h"
#include "GameObject.h"
#include "Sprite.h"
#include "Sound.h"
#include "Spell.h"


// Inheritance - IS-A 
// Containment - HAS-A


//my Player IS-A game Obj.
class Player : public GameObject
{

public:

	enum State
	{
		Idle,
		MovingUp,
		MovingDown,
		MovingLeft,
		MovingRight,
		CastingUp,
		CastingDown,
		CastingLeft,
		CastingRight,
		TotalStates
	};

	Player();
	~Player();

	void SetVelocity(const int& velocity);
	void SetState(const State& state);
	const BoxCollider& GetCollider() const;

	bool GetCasting() const;

	virtual void Update();
	virtual void Render();

private:
	//TODO -- HP AND MP STATS
	State m_state{ Idle };
	//Spell* m_spell;       //pointer to 'Spell' object (dynamic creation)
	//std::unique_ptr<Spell> m_spell;
	Sprite m_images[TotalStates], m_necromancerHud,m_playerHud, m_playerHpBar, m_playerMpBar;       //containment - player has an image
	//Sound m_spellCast, m_footSteps;
	Sound m_footSteps;

	std::deque<Spell> m_spells;

	bool isCasting{ false };
	int m_velocity{ 1 };
	Vector<int> m_direction, m_spellPosition, m_mousePosition;

	BoxCollider m_collider;
	//SphereCollider m_collider;
};