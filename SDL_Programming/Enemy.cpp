#include "Enemy.h"
#include "Game.h"


Enemy::Enemy(const std::string& enemyName)
{
	//m_images[Idle].Load("Assets/Images/Enemy/Goblin/Idle.png");
	m_images[Moving].Load("Assets/Images/Enemy/" + enemyName + "/Moving.png");
	m_images[Attacking].Load("Assets/Images/Enemy/" + enemyName + "/Attack.png");
	m_images[TakingHit].Load("Assets/Images/Enemy/" + enemyName + "/TakeHit.png");
	m_images[Death].Load("Assets/Images/Enemy/" + enemyName + "/Death.png");

	for (int i = 0; i < State::TotalStates; i++)
	{
		m_images[i].SetImageDimension(8, 1, 1200, 150);
		m_images[i].SetSpriteDimension(150, 150);
		m_images[i].IsAnimated(true);
		m_images[i].SetAnimationVelocity(0.4f);
		m_images[i].IsAnimationLooping(true);
		
		if (i == State::Death || i == State::TakingHit || i == State::Attacking)
		{
			m_images[i].IsAnimationLooping(false);
		}

		m_velocity = 2;
		m_damage = 25;
	}
	//Respawn Location

	//MONSTER HP BAR
	m_monsterHP.Load("Assets/Images/Character/Info/monsterHP.png");
	m_monsterHP.SetImageDimension(1, 1, 181, 11);
	m_monsterHP.SetSpriteDimension(50, 5);
	
	m_monsterRedHP.Load("Assets/Images/Character/Info/monsterRedHP.png");
	m_monsterRedHP.SetImageDimension(1, 1, 181, 11);
	m_monsterRedHP.SetSpriteDimension(50, 5);

	m_maxHealthPoints = 50;
	m_healthPoints = m_maxHealthPoints;
	m_loseHealth = 0;

	m_collider.SetDimension(50, 50);
}

Enemy::~Enemy()
{
	for (int i = 0; i < State::TotalStates; i++)
	{
		m_images[i].Unload();
	}

	m_monsterHP.Unload();
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
	if (IsAlive() && m_state == Enemy::State::Moving)
	{
		m_direction = playerPosition - m_position;

		Vector<float> dir;
		dir.x = static_cast<float>(m_direction.x);
		dir.y = static_cast<float>(m_direction.y);

		dir = dir.Normalize();
		dir *= static_cast<float>(m_velocity);

		Vector<int> d;
		d.x = static_cast<int>(dir.x);
		d.y = static_cast<int>(dir.y);

		m_position += d;
	}
	//TODO FAMILIAR POSITION
	//m_direction = playerPosition - m_position - m_images[m_state].GetCentrePosition();
}

void Enemy::SetLooseHealth(int looseHealth)
{
	m_loseHealth += looseHealth;
}

void Enemy::SetDamage(int damage)
{
	m_damage += damage;
}

void Enemy::ReceiveDamage(const int playerDamage)
{
	m_healthPoints -= playerDamage;

	if (m_healthPoints <= 0 && m_isAlive == true)
	{
		m_healthPoints = 0;
		m_isAlive = false;
		SetState(State::Death);
	}
	SetState(State::TakingHit);
	SetLooseHealth(playerDamage);
}

void Enemy::SetVelocity(int velocity)
{
	m_velocity += velocity;
}

int Enemy::GetDamage() const
{
	return m_damage;
}

int Enemy::GetHealth() const
{
	return m_healthPoints;
}
Sprite Enemy::GetImages()
{
	return m_images[m_state];
}

Enemy::State Enemy::GetState()
{
	return m_state;
}

const BoxCollider& Enemy::GetCollider() const
{
	return m_collider;
}

void Enemy::SetState(const State& state)
{
	if (state == State::TakingHit || state == State::Attacking)
	{
		m_images[state].SetImageCel(8, 1);
		m_images[state].IsAnimationDead(false);
	}
	m_state = state;
}

void Enemy::Respawn(int posX, int posY)
{
	m_position.x = posX;
	m_position.y = posY;
}

void Enemy::Update()
{
	if (m_images[m_state].IsAnimationDead() && IsAlive())
	{
		SetState(State::Moving);
	}
	if (!IsAlive())
	{
		SetState(State::Death);
		if (GetState() == Enemy::State::Death && m_images[m_state].IsAnimationDead())
		{

		}
	}
		
	m_collider.SetPosition(m_position.x + 50, m_position.y + 50);
	m_collider.Update();

	if (m_monsterHP.GetSpriteDimension().x > 0 && m_loseHealth > 0)
	{
		m_monsterHP.SetSpriteDimension(m_monsterHP.GetSpriteDimension().x - 1, m_monsterHP.GetSpriteDimension().y);
		SetLooseHealth(-1);
		std::cout << m_loseHealth << std::endl;
	}
	
	m_monsterHP.Update();
	m_monsterRedHP.Update();
	m_images[m_state].Update();
}

void Enemy::Render()
{
	m_images[m_state].Render(m_position.x, m_position.y, m_angle);

	if (IsAlive())
	{
		m_monsterRedHP.Render(m_position.x + 50, m_position.y + 50, m_angle);
		m_monsterHP.Render(m_position.x + 50, m_position.y + 50, m_angle);
		//m_collider.Render();
	}
}
