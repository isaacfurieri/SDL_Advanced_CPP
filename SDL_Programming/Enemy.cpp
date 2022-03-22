#include "Enemy.h"


Enemy::Enemy(Screen* screen)
{
	m_image.Load("Assets/Images/Character/Enemy/Enemy.png", screen);
	m_image.IsAnimationLooping(false);
	m_image.SetImageDimension(1, 1, 72, 96);
	m_image.SetSpriteDimension(72, 96);
	m_image.IsAnimated(false);
	//m_image.SetAnimationVelocity(1.5f);
	m_velocity = 0;
	isAlive = true;
}

Enemy::~Enemy()
{
	m_image.Unload();
}

void Enemy::SetVelocity(int velocity)
{
	m_velocity = velocity;
}

const BoxCollider& Enemy::GetCollider() const
{
	return m_collider;
}

void Enemy::Respawn(int posX, int posY)
{
	m_position.x = posX;
	m_position.y = posY;
}

void Enemy::Update(Input& input)
{
	m_direction = m_direction.Scale(m_velocity);
	m_position = m_position.Add(m_direction);

	m_image.Update();

	m_collider.SetDimension(m_size.x, m_size.y);
	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.Update();
}

void Enemy::Render(Screen* screen)
{
	m_image.Render(m_position.x, m_position.y, m_angle, screen);
}
