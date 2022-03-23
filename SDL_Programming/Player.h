#pragma once
#include <iostream>

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

	void SetVelocity(int velocity);
	void SetState(State state);
	const BoxCollider& GetCollider() const;

	bool GetCasting() const;

	virtual void Update(Input* input);
	virtual void Render(Screen* screen);

private:

	State m_state;
	Spell* m_spell;       //pointer to 'Spell' object (dynamic creation)
	Sprite m_images[TotalStates];       //containment - player has an image
	Sound m_spellCast, m_footSteps;

	bool isCasting;
	int m_velocity;
	Vector2D m_direction, m_spellPosition, m_mousePosition;

	BoxCollider m_collider;
	//SphereCollider m_collider;
};