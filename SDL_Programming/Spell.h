#pragma once

#include <iostream>

#include "BoxCollider.h"
#include "GameObject.h"
#include "Screen.h"
#include "Sound.h"
#include "Sprite.h"

class Spell : public GameObject
{

public:

	enum class SpellState
	{
		Moving,
		Explosion,
		TotalStates
	};

	Spell(Vector<int>& spellPosition, Vector<int>& mousePosition);
	~Spell();

	void ChangeState(SpellState state);

	const BoxCollider& GetCollider() const;
	const Spell::SpellState GetState() const;
	Sprite GetImage();

	virtual void Update();
	virtual void Render();

private:

	int m_spellSpeed;

	BoxCollider m_collider;
	SpellState m_state{ SpellState::Moving };
	Sprite m_image[static_cast<int>(SpellState::TotalStates)], m_explosion;
	Vector<int> m_direction, m_mousePosition;
};