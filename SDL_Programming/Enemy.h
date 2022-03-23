#pragma once

#include <iostream>

#include "BoxCollider.h"
#include "GameObject.h"
#include "Sprite.h"
#include "Sound.h"
#include "Spell.h"

class Enemy : public GameObject
{
	public:
		Enemy();
		~Enemy();

		void SetVelocity(int velocity);
		const BoxCollider& GetCollider() const;
		void Respawn(int posX, int posY);

		virtual void Update();
		virtual void Render();

private:

	Sprite m_image;       //containment - enemy has an image
	Sound m_dead;

	bool isAlive;
	int m_velocity;
	Vector<int> m_direction;

	BoxCollider m_collider;
};

