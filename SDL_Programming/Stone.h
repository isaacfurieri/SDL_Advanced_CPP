#pragma once

#include "BoxCollider.h"
#include "GameObject.h"
#include "Sprite.h"
#include "SphereCollider.h"

class Stone : public GameObject
{

public:

	Stone(Screen* screen);
	~Stone();

	void SetVelocity(int velocity);
	const BoxCollider& GetCollider() const;
	//const SphereCollider& GetCollider() const;

	virtual void Update(Input& input);
	virtual void Render(Screen* screen);

private:

	Sprite m_image;

	int m_velocity;
	Vector2D m_direction;
	BoxCollider m_collider;
	//SphereCollider m_collider;
};