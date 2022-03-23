
#include "Spell.h"

Spell::Spell(Screen* screen, Vector2D& spellPosition, Vector2D& mousePosition)
{
	m_image.Load("Assets/Images/Character/GreenFireball.png", screen);
	m_image.SetImageDimension(1, 1, 50, 50);
	m_image.SetSpriteDimension(50, 50);

	m_image.IsAnimated(false);
	m_image.IsAnimationLooping(false);
	//m_image.SetAnimationVelocity(1.1f);

	m_position = spellPosition;
	m_mousePosition = mousePosition;
}

const BoxCollider& Spell::GetCollider() const
{
	return m_collider;
}

void Spell::Update(Input* input)
{
	m_direction = m_mousePosition.Subtract(m_position);
	
	//m_direction = m_direction.Normalize();
	m_direction = m_direction.Scale(0.03f);

	m_position = m_position.Add(m_direction);

	m_image.Update();

	m_collider.SetDimension(m_size.x, m_size.y);
	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.Update();
}

void Spell::Render(Screen* screen)
{
	m_image.Render(m_position.x, m_position.y, m_angle, screen);
}