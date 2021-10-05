#pragma once
#include <iostream>

#include "BoxCollider.h"
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
		IDLE,
		MOVING_UP,
		MOVING_DOWN,
		MOVING_LEFT,
		MOVING_RIGHT,
		CASTING_UP,
		CASTING_DOWN,
		CASTING_LEFT,
		CASTING_RIGHT,
		TOTAL_STATES
	};

	Player(Screen& screen);
	~Player();

	void SetVelocity(int velocity);
	void SetState(State state);
	const BoxCollider& GetCollider() const;

	bool GetCasting() const;

	virtual void Update(Input& input);
	virtual void Render(Screen& screen);

private:

	State m_state;
	Spell* m_spell;       //pointer to 'Spell' object (dynamic creation)
	Sprite m_images[TOTAL_STATES];       //containment - player has an image
	Screen& m_screen;
	Sound m_spellCast, m_footSteps;

	bool isCasting;
	int m_velocity;
	Vector2D m_direction, m_spellPosition, m_mousePosition;

	BoxCollider m_collider;
	//SphereCollider m_collider;
};