#pragma once

#include "BoxCollider.h"
#include "GameObject.h"
#include "Sprite.h"

class Coin : public GameObject
{

public:

	Coin(Screen& screen);
	~Coin();

	const BoxCollider& GetCollider() const;
	void RespawnObject(int posX, int posY);

	virtual void Update(Input& input);
	virtual void Render(Screen& screen);

private:

	Sprite m_image;

	Vector2D m_direction;
	BoxCollider m_collider;
};