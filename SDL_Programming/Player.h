#pragma once
#include <iostream>
#include <deque>
#include "BoxCollider.h"
#include "Game.h"
#include "GameObject.h"
#include "Sprite.h"
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

	int GetDamage() const;
	int GetHealthPoints() const;
	int GetManaPoints() const;
	
	void ReceiveDamage(const int monsterDamage);
	void SetHealthPoints(int healthPoints);
	void SetLooseHealth(int looseHealth);
	void SetMaxHealthPoints(int maxHealth);
	void SetManaPoints(int manaPoints);
	void SetMaxManaPoints(int manaPoints);
	void SetState(const State& state);
	void SetVelocity(const int& velocity);

	Sprite GetImages() const;

	const BoxCollider& GetCollider() const;
	//std::deque<Spell> GetSpells();
	Spell* GetSpellPtr();
	bool GetCasting() const;

	virtual void Update();
	virtual void Render();

private:
	//TODO -- MP STATS
	State m_state{ State::Idle };
	Spell* m_fireballSpell = nullptr;       //pointer to 'Spell' object (dynamic creation)
	Sprite m_images[State::TotalStates], m_necromancerHud,m_playerHud, m_playerHpBar, m_playerMpBar, m_playerSpellHud;       //containment - player has an image
	BoxCollider m_collider;

	//TODO DEQUE OF SPELLS TO CAST DIIFERENT SPELLS
	//std::deque<Spell> m_spells;
	std::deque<HealSpell> m_Healspells;
	Vector<int> m_direction, m_spellPosition, m_mousePosition;

	bool m_isCasting{ false };
	float m_spellCoolDown = 0;
	float m_healingSpellCoolDown = 0;
	int m_damage;
	int m_velocity{ 1 };
	int m_healthPoints, m_manaPoints, m_maxHealthPoints, m_maxManaPoints, m_loseHealth;
	int m_maxHealthBarSize, m_maxManaBarSize;

	//SphereCollider m_collider;
};