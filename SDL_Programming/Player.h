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

	int GetDamage() const;
	int GetHealthPoints() const;
	int GetManaPoints() const;
	
	void ReceiveDamage(const int monsterDamage);
	void UpdateHealthBar(float updatePercent);
	void SetHealthPoints(int healthPoints);
	void SetLooseHealth(int looseHealth);
	void SetMaxHealthPoints(int maxHealth);
	void SetManaPoints(int manaPoints);
	void SetMaxManaPoints(int manaPoints);
	void SetState(const State& state);
	void SetVelocity(const int& velocity);

	Sprite GetImages() const;

	const BoxCollider& GetCollider() const;
	const std::deque<Spell> GetSpells() const;

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
	float m_spellCoolDown = 0;
	float m_healingSpellCoolDown = 0;
	int m_damage;
	int m_velocity{ 1 };
	int m_healthPoints, m_manaPoints, m_maxHealthPoints, m_maxManaPoints, m_loseHealth;
	int m_maxHealthBarSize, m_maxManaBarSize;
	Vector<int> m_direction, m_spellPosition, m_mousePosition;

	BoxCollider m_collider;
	//SphereCollider m_collider;
};