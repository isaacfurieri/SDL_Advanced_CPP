#include "Enemy.h"


Enemy::Enemy()
{
	m_images[Idle].Load("Assets/Images/Enemy/Flying_eye/Flight.png");
	m_images[Moving].Load("Assets/Images/Enemy/Flying_eye/Flight.png");
	m_images[Attacking].Load("Assets/Images/Enemy/Flying_eye/Attack.png");
	m_images[TakingHit].Load("Assets/Images/Enemy/Flying_eye/Take_Hit.png");
	m_images[Death].Load("Assets/Images/Enemy/Flying_eye/Death.png");

	for (int i = 0; i < State::TotalStates; i++)
	{
		m_images[i].SetImageDimension(8, 1, 1200, 150);
		m_images[i].SetSpriteDimension(300, 300);
		m_images[i].IsAnimated(true);
		m_images[i].SetAnimationVelocity(0.50f);

		m_images[i].IsAnimationLooping(true);
		
		if (i == State::Death)
		{
			m_images[i].IsAnimationLooping(false);
		}
		m_velocity = 2;
		m_damage = 20;
	}

	m_collider.SetDimension(m_images[m_state].GetSpriteDimension().x, m_images[m_state].GetSpriteDimension().y);
}

Enemy::~Enemy()
{
	for (int i = 0; i < State::TotalStates; i++)
	{
		m_images[i].Unload();
	}
}

void Enemy::FlipToPlayer(Vector<int> playerPosition)
{
	for (int i = 0; i < State::TotalStates; i++)
	{
		m_images[i].FlipImage(playerPosition, m_position);
	}
}

void Enemy::UpdateDirection(Vector<int> playerPosition)
{
	m_direction = playerPosition - m_position;

	//TODO FAMILIAR POSITION
	//m_direction = playerPosition - m_position - m_images[m_state].GetCentrePosition();
}

void Enemy::SetVelocity(int velocity)
{
	m_velocity = velocity;
}

int Enemy::GetDamage() const
{
	return m_damage;
}

const BoxCollider& Enemy::GetCollider() const
{
	return m_collider;
}

void Enemy::SetState(const State& state)
{
	m_state = state;
}

void Enemy::Respawn(int posX, int posY)
{
	m_position.x = posX;
	m_position.y = posY;
}

void Enemy::Update()
{

	Vector<float> dir;
	dir.x = static_cast<float>(m_direction.x);
	dir.y = static_cast<float>(m_direction.y);

	dir = dir.Normalize();
	dir *= static_cast<float>(m_velocity);

	Vector<int> d;
	d.x = static_cast<int>(dir.x);
	d.y = static_cast<int>(dir.y);

	m_position += d;


	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.Update();

	m_images[m_state].Update();
}

void Enemy::Render()
{
	m_images[m_state].Render(m_position.x, m_position.y, m_angle);
}
