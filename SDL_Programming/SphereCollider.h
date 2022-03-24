#pragma once

#include "Vector.h"

class SphereCollider
{
public:

	SphereCollider();

	void SetRadius(int radius);
	void SetPosition(int x, int y);

	bool IsColliding(const SphereCollider& secondBox) const;

private:

	int m_radius;
	Vector<int> m_position;
};