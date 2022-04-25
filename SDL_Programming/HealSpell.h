#pragma once

#include "BoxCollider.h"
#include "GameObject.h"
#include "Screen.h"
#include "Sound.h"
#include "Sprite.h"

class HealSpell : public GameObject
{
public:

	HealSpell(Vector<int>& spellPosition);

	virtual void Update();
	virtual void Render();

private:

	Sound m_spellSound;
	Sprite m_image;
};

