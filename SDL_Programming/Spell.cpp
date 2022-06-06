#include "Spell.h"

Spell::Spell(Vector<int>& spellPosition, Vector<int>& mousePosition)
{
	//m_image.Load("Assets/Images/Character/GreenFireball.png");
	m_image[static_cast<int>(SpellState::Moving)].Load("Assets/Images/Character/fireBall.png");
	m_image[static_cast<int>(SpellState::Explosion)].Load("Assets/Images/Character/Explosion.png");

	for (auto i = 0; i < static_cast<int>(SpellState::TotalStates); i++)
	{
		m_image[i].SetImageDimension(8, 1, 800, 100);
		m_image[i].SetSpriteDimension(50, 50);
		m_image[i].IsAnimated(true);
		m_image[i].SetAnimationVelocity(0.5f);
	}
	
	m_image[static_cast<int>(SpellState::Moving)].IsAnimationLooping(true);
	m_image[static_cast<int>(SpellState::Moving)].SetFlipImage(spellPosition, mousePosition);

	m_image[static_cast<int>(SpellState::Explosion)].IsAnimationLooping(false);

	m_spellSpeed = 10;
	m_position = spellPosition;
	m_mousePosition = mousePosition;

	m_collider.SetDimension(50, 50);

	m_angle = static_cast<float>(m_position.Angle(m_mousePosition) * static_cast<int>(180 / M_PI));
	m_direction = m_mousePosition - m_position;

	//Change Sound to game state
	//m_spellSound.Load("Assets/Music/fireball_cast.wav");
	//m_spellSound.Play(0);
}

Spell::~Spell()
{
	//m_image.Unload();
	//m_spellSound.Unload();
}

void Spell::ChangeState(SpellState state)
{
	m_state = state;
	m_direction = m_position;
}

const BoxCollider& Spell::GetCollider() const
{
	return m_collider;
}

Sprite Spell::GetImage()
{
	return m_image[static_cast<int>(m_state)];
}

const Spell::SpellState Spell::GetState() const
{
	return m_state;
}

void Spell::Update()
{
	if (IsAlive())
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
	
	}
	else
	{
		m_image[static_cast<int>(SpellState::Moving)].IsAnimationLooping(false);
	}
	m_image[static_cast<int>(GetState())].Update();
	
	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.Update();
}

void Spell::Render()
{
	m_image[static_cast<int>(GetState())].Render(m_position.x, m_position.y, m_angle);
	//m_collider.Render();
}