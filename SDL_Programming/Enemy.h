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
		Enemy(Screen* screen);
		~Enemy();

		void SetVelocity(int velocity);
		const BoxCollider& GetCollider() const;
		void Respawn(int posX, int posY);

		virtual void Update(Input* input);
		virtual void Render(Screen* screen);

private:

	Sprite m_image;       //containment - enemy has an image
	Sound m_dead;

	bool isAlive;
	int m_velocity;
	Vector2D m_direction;

	BoxCollider m_collider;
};

