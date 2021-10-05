#include "Stone.h"

Stone::Stone(Screen& screen)
{
	m_velocity = 0;
	m_image.Load("Assets/Images/Background/Stone.png", screen);
	m_image.IsAnimationLooping(false);
	m_image.SetImageDimension(1, 1, 22, 20);
	m_image.SetSpriteDimension(100, 100);
	m_image.IsAnimated(false);
}

Stone::~Stone()
{
	m_image.Unload();
}

void Stone::SetVelocity(int velocity)
{
	m_velocity = velocity;
}

//const SphereCollider& Stone::GetCollider() const
//{
//	return m_collider;
//}

const BoxCollider& Stone::GetCollider() const
{
	return m_collider;
}

void Stone::Update(Input& input)
{
	m_collider.SetDimension(m_size.x, m_size.y);
	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.Update();

	m_image.Update();

	//m_collider.SetRadius(m_size.x / 2);
	//m_collider.SetPosition(m_position.x, m_position.y);
}

void Stone::Render(Screen& screen)
{
	m_image.Render(m_position.x, m_position.y, m_angle, screen);
}