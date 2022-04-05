#pragma once

#include "BoxCollider.h"
#include "GameObject.h"
#include "Screen.h"
#include "Sound.h"
#include "Sprite.h"

class Spell : public GameObject
{

public:

	Spell(Vector<int>& spellPosition, Vector<int>& mousePosition);

	const BoxCollider& GetCollider() const;

	virtual void Update();
	virtual void Render();

private:

	int m_spellSpeed;

	BoxCollider m_collider;
	Sound m_spellSound;
	Sprite m_image;
	Vector<int> m_direction, m_mousePosition;
};