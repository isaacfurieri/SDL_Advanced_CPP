#pragma once

#include "Vector.h"
#include "Sprite.h"

class BoxCollider
{
public:

	BoxCollider();
	~BoxCollider();

	void SetPosition(int x, int y);
	void SetDimension(int width, int height);

	void Update();
	void Render();
	bool IsColliding(const BoxCollider& secondBox) const;

private:

	Sprite m_image;
	Vector<int> m_min;
	Vector<int> m_max;
	Vector<int> m_position;
	Vector<int> m_dimension;
};