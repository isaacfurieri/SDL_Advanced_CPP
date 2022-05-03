#pragma once
#include <iostream>
#include <deque>
#include "BoxCollider.h"
#include "Game.h"
#include "GameObject.h"
#include "Sprite.h"
#include "Sound.h"
#include "HealSpell.h"
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
	State m_state{ State::Idle };
	//Spell* m_spell;       //pointer to 'Spell' object (dynamic creation)
	//std::unique_ptr<Spell> m_spell;
	Sprite m_images[State::TotalStates], m_necromancerHud,m_playerHud, m_playerHpBar, m_playerMpBar, m_playerSpellHud;       //containment - player has an image
	//Sound m_spellCast, m_footSteps;
	Sound m_footSteps;

	std::deque<Spell> m_spells;
	std::deque<HealSpell> m_Healspells;

	bool m_isCasting{ false };
	int m_velocity{ 1 };
	float m_spellCoolDown = 0;
	float m_healingSpellCoolDown = 0;
	Vector<int> m_direction, m_spellPosition, m_mousePosition;

	BoxCollider m_collider;
	//SphereCollider m_collider;
};