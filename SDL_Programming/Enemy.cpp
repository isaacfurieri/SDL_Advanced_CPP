#include "Enemy.h"


Enemy::Enemy()
{
	m_image.Load("Assets/Images/Enemy/Flying_eye/Flight.png");
	m_image.IsAnimationLooping(true);
	m_image.SetImageDimension(8, 1, 1200, 150);
	m_image.SetSpriteDimension(300, 300);
	m_image.IsAnimated(true);
	m_image.SetAnimationVelocity(1.0f);
	m_velocity = 0;
	m_damage = 20;
}

Enemy::~Enemy()
{
	m_image.Unload();
}

void Enemy::FlipToPlayer(Vector<int> playerPosition)
{
	m_image.FlipImage(playerPosition, m_position);
}

void Enemy::SetVelocity(int velocity)
{
	m_velocity = velocity;
}

int Enemy::GetDamage() const
{
	return m_damage;
}

Sprite Enemy::GetImage() const
{
	return m_image;
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

void Enemy::Update()
{
	m_direction = m_direction * m_velocity;
	m_position = m_position + m_direction;

	m_image.Update();

	m_collider.SetDimension(m_size.x, m_size.y);
	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.Update();
}

void Enemy::Render()
{
	m_image.Render(m_position.x, m_position.y, m_angle);
}
