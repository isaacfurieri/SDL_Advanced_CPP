#include "SphereCollider.h"

SphereCollider::SphereCollider()
{
	m_radius = 0;
}

void SphereCollider::SetRadius(int radius)
{
	m_radius = radius;
}

void SphereCollider::SetPosition(int x, int y)
{
	m_position.x = x;
	m_position.y = y;
}

bool SphereCollider::IsColliding(const SphereCollider& secondBox) const
{
	Vector<int> centerPointA = Vector<int>(m_position.x + m_radius, m_position.y + m_radius);
	Vector<int> centerPointB = Vector<int>(secondBox.m_position.x + m_radius,
		secondBox.m_position.y + m_radius);

	int distanceBetweenPoints = centerPointA.Distance(centerPointB);

	return (distanceBetweenPoints <= (m_radius + secondBox.m_radius));
}