#include "HealSpell.h"

HealSpell::HealSpell(Vector<int>& spellPosition)
{
	m_image.Load("Assets/Images/Character/Heal.png");
	m_image.SetImageDimension(6, 1, 384, 64);
	m_image.SetSpriteDimension(75, 75);
	m_image.SetAnimationVelocity(0.2f);
	m_image.IsAnimated(true);
	m_image.IsAnimationLooping(false);

	m_position = spellPosition;

	m_spellSound.Load("Assets/Sounds/healingspell.wav");
	m_spellSound.Play(0);
}

bool HealSpell::AnimationSpell()
{
	return m_image.IsAnimationDead();
}

void HealSpell::Update()
{
	m_image.Update();
}

void HealSpell::Render()
{
	m_image.Render(m_position.x, m_position.y, m_angle);
}
