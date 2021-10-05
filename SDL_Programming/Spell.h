#pragma once

#include "BoxCollider.h"
#include "GameObject.h"
#include "Screen.h"
#include "Sound.h"
#include "Sprite.h"

class Spell : public GameObject
{

public:

	Spell(Screen& screen, Vector2D& spellPosition, Vector2D& mousePosition);

	const BoxCollider& GetCollider() const;

	virtual void Update(Input& input);
	virtual void Render(Screen& screen);

private:

	Sprite m_image;
	Vector2D m_direction, m_mousePosition;
	BoxCollider m_collider;
};