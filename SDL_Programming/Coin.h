#pragma once

#include "BoxCollider.h"
#include "GameObject.h"
#include "Sprite.h"

class Coin : public GameObject
{

public:

	Coin();
	~Coin();

	const BoxCollider& GetCollider() const;
	void RespawnObject(int posX, int posY);

	virtual void Update();
	virtual void Render();

private:

	Sprite m_image;

	Vector<int> m_direction;
	BoxCollider m_collider;
};