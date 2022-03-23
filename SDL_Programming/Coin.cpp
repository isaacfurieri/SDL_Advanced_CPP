#include <stdlib.h>
#include <time.h>
#include "Coin.h"

Coin::Coin()
{
	m_image.Load("Assets/Images/Coin_gold.png");
	m_image.SetImageDimension(6, 1, 3072, 512);
	m_image.IsAnimationLooping(true);
	m_image.SetSpriteDimension(50, 50);
	m_image.IsAnimated(true);
	m_image.SetAnimationVelocity(1.5f);
}

Coin::~Coin()
{
	m_image.Unload();
}

const BoxCollider& Coin::GetCollider() const
{
	return m_collider;
}

void Coin::RespawnObject(int posX, int posY)
{
	m_position.x = posX;
	m_position.y = posY;
}

void Coin::Update()
{
	m_collider.SetDimension(m_size.x, m_size.y);
	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.Update();
}

void Coin::Render()
{
	m_image.Render(m_position.x, m_position.y, m_angle);
}
