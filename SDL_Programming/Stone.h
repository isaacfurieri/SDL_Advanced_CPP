#pragma once

#include "BoxCollider.h"
#include "GameObject.h"
#include "Sprite.h"
#include "SphereCollider.h"

class Stone : public GameObject
{

public:

	Stone();
	~Stone();

	void SetVelocity(int velocity);
	const BoxCollider& GetCollider() const;
	//const SphereCollider& GetCollider() const;

	virtual void Update();
	virtual void Render();

private:

	Sprite m_image;

	int m_velocity;
	Vector<int> m_direction;
	BoxCollider m_collider;
	//SphereCollider m_collider;
};