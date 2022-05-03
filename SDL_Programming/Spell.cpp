#include "Spell.h"

Spell::Spell(Vector<int>& spellPosition, Vector<int>& mousePosition)
{
	//m_image.Load("Assets/Images/Character/GreenFireball.png");
	m_image.Load("Assets/Images/Character/fireBall.png");
	m_image.SetImageDimension(8, 8, 800, 800);
	m_image.SetSpriteDimension(150, 150);

	m_image.IsAnimated(true);
	m_image.IsAnimationLooping(true);
	m_image.SetAnimationVelocity(1.5f);
	m_image.SetFlipImage(spellPosition, mousePosition);

	m_spellSpeed = 20;
	m_position = spellPosition;
	m_mousePosition = mousePosition;


	m_angle = m_position.Angle(m_mousePosition) * 180 / M_PI;
	m_direction = m_mousePosition - m_position;

	m_spellSound.Load("Assets/Music/fireball_cast.wav");
	m_spellSound.Play(0);

}

Spell::~Spell()
{
	//m_image.Unload();
	//m_spellSound.Unload();
}

const BoxCollider& Spell::GetCollider() const
{
	return m_collider;
}

void Spell::Update()
{
	Vector<float> dir;
	dir.x = static_cast<float>(m_direction.x);
	dir.y = static_cast<float>(m_direction.y);

	dir = dir.Normalize();
	dir *= static_cast<float>(m_spellSpeed);

	Vector<int> d;
	d.x = static_cast<int>(dir.x);
	d.y = static_cast<int>(dir.y);

	m_position = m_position + d;

	m_image.Update();

	m_collider.SetDimension(m_size.x, m_size.y);
	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.Update();
}

void Spell::Render()
{
	m_image.Render(m_position.x, m_position.y, m_angle);
}