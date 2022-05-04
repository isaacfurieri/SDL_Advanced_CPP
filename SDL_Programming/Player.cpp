#include "Player.h"

Player::Player()
{
	//==========================================================
	//LOADING ASSETS
	m_images[Idle].Load("Assets/Images/Character/Necromancer/PlayerSpriteIdle.png");
	m_images[MovingUp].Load("Assets/Images/Character/Necromancer/PlayerSpriteMovingUp.png");
	m_images[MovingDown].Load("Assets/Images/Character/Necromancer/PlayerSpriteMovingDown.png");
	m_images[MovingLeft].Load("Assets/Images/Character/Necromancer/PlayerSpriteMovingLeft.png");
	m_images[MovingRight].Load("Assets/Images/Character/Necromancer/PlayerSpriteMovingRight.png");
	m_images[CastingUp].Load("Assets/Images/Character/Necromancer/PlayerSpriteCastingUp.png");
	m_images[CastingDown].Load("Assets/Images/Character/Necromancer/PlayerSpriteCastingDown.png");
	m_images[CastingLeft].Load("Assets/Images/Character/Necromancer/PlayerSpriteCastingLeft.png");
	m_images[CastingRight].Load("Assets/Images/Character/Necromancer/PlayerSpriteCastingRight.png");

	for (int i = 0; i < State::TotalStates; i++)
	{
		m_images[i].IsAnimationLooping(true);
		m_images[i].SetSpriteDimension(150, 150);
		m_images[i].IsAnimated(true);
		m_images[i].SetAnimationVelocity(0.5f);
		m_images[i].SetImageDimension(9, 1, 360, 40);
	}

	m_playerSpellHud.Load("Assets/Images/Character/Hud/SpellHud.png");
	m_playerSpellHud.SetImageDimension(10, 9, 1000, 900);
	m_playerSpellHud.IsAnimationLooping(true);
	m_playerSpellHud.IsAnimated(true);
	m_playerSpellHud.SetAnimationVelocity(5.0f);
	m_playerSpellHud.SetSpriteDimension(95,95);


	m_necromancerHud.Load("Assets/Images/Character/Hud/NecromancerHud.png");
	m_necromancerHud.SetImageDimension(1, 1, 67, 55);
	m_necromancerHud.SetSpriteDimension(63, 55);

	m_playerHud.Load("Assets/Images/Character/Hud/PlayerHud.png");
	m_playerHud.SetImageDimension(1, 1, 273, 74);
	m_playerHud.SetSpriteDimension(280,75);

	m_playerHpBar.Load("Assets/Images/Character/Hud/PlayerHpBar.png");
	m_playerHpBar.SetImageDimension(1, 1, 174, 24);
	m_playerHpBar.SetSpriteDimension(187, 24);
	m_maxHealthBarSize = m_playerHpBar.GetSpriteDimension().x;
	m_playerMpBar.Load("Assets/Images/Character/Hud/PlayerMpBar.png");
	m_playerMpBar.SetImageDimension(1, 1, 206, 24);
	m_playerMpBar.SetSpriteDimension(208, 24);
	m_maxManaBarSize = m_playerMpBar.GetImageDimension().x;
	//==========================================================
	//Sounds
	m_footSteps.Load("Assets/Music/footsteps_walking.wav");
	
	//==========================================================
	//Character Setup
	m_maxHealthPoints = 150;
	m_maxManaPoints = 150;
	m_healthPoints = m_maxHealthPoints;
	m_manaPoints = m_maxManaPoints;
	//==========================================================

}

Player::~Player()
{
	for (int i = 0; i < TotalStates; i++)
	{
		m_images[i].Unload();
	}

	m_necromancerHud.Unload();
	m_playerHud.Unload();
	m_playerHpBar.Unload();
	m_playerMpBar.Unload();
	m_playerSpellHud.Unload();
	m_spells.~deque();
	m_Healspells.~deque();
}

int Player::GetHealthPoints() const
{
	return m_healthPoints;
}

int Player::GetManaPoints() const
{
	return m_manaPoints;
}

void Player::ReceiveDamage(const int monsterDamage)
{
	m_healthPoints -= monsterDamage;

	if (m_healthPoints <= 0)
	{
		m_healthPoints = 0;
		m_isAlive = false;
	}

	UpdateHealthBar(static_cast<float>((m_maxHealthPoints * monsterDamage) / 100));
}

void Player::UpdateHealthBar(float updatePercent)
{
	auto spritePercent = (m_maxHealthBarSize / 100) * updatePercent;

	m_playerHpBar.SetSpriteDimension(m_playerHpBar.GetSpriteDimension().x - spritePercent, m_playerHpBar.GetSpriteDimension().y);
}

void Player::SetHealthPoints(int healthPoints)
{
	if (m_healthPoints + healthPoints > m_maxHealthPoints)
	{
		m_healthPoints = m_maxHealthPoints;
	}
	else
	{
		m_healthPoints += healthPoints;
	}
}

void Player::SetMaxHealthPoints(int maxHealth)
{
	m_maxHealthPoints += maxHealth;
}

void Player::SetManaPoints(int manaPoints)
{
	if (m_manaPoints + manaPoints > m_maxManaPoints)
	{
		m_manaPoints = m_maxManaPoints;
	}
	else
	{
		m_manaPoints += manaPoints;
	}
}

void Player::SetMaxManaPoints(int manaPoints)
{

	m_maxManaPoints += manaPoints;
}

void Player::SetVelocity(const int& velocity)
{
	m_velocity = velocity;
}

void Player::SetState(const State& state)
{
	m_state = state;
}

//const SphereCollider& Player::GetCollider() const
//{
//	return m_collider;
//}

const BoxCollider& Player::GetCollider() const
{
	return m_collider;
}

bool Player::GetCasting() const
{
	return m_isCasting;
}

void Player::Update()
{
	auto input = Input::Instance();
	
	m_mousePosition = input->GetMousePosition();
	
	//Manupulate/Read keys here
	//UP DOWN LEFT RIGHT ARROW KEYS MOVIMENT
	//==========================================================

	auto ChangeStateAndDir = [&](State castingState, State movingState, const Vector<int>& direction) 
	{
		if (m_isCasting)
		{
			m_state = castingState;
		}
		else if (!m_isCasting)
		{
			m_state = movingState;
		}
		m_direction = direction;
	};

	//TODO -- DIAGONAL MOVEMENTS IF PRESSING TWO BUTTONS

	if (input->IsKeyPressed(HM_KEY_RIGHT) || input->IsKeyPressed(HM_KEY_D))
	{
		ChangeStateAndDir(CastingRight, MovingRight, Vector<int>(1, 0));
	}
	else if (input->IsKeyPressed(HM_KEY_LEFT) || input->IsKeyPressed(HM_KEY_A))
	{
		ChangeStateAndDir(CastingLeft, MovingLeft, Vector<int>(-1, 0));
	}
	else if (input->IsKeyPressed(HM_KEY_UP) || input->IsKeyPressed(HM_KEY_W))
	{
		ChangeStateAndDir(CastingUp, MovingUp, Vector<int>(0, -1));
	}
	else if (input->IsKeyPressed(HM_KEY_DOWN) || input->IsKeyPressed(HM_KEY_S))
	{
		ChangeStateAndDir(CastingDown, MovingDown, Vector<int>(0, 1));
	}
	else
	{
		ChangeStateAndDir(CastingDown, Idle, Vector<int>(0, 0));
	}
	//Apply image State and Direction after Update.
	m_direction = m_direction * m_velocity;
	m_images[m_state].Update();

	//==========================================================
	//Checking screen size to prevent moving away
	if (m_position.x < 20) 
	{
		std::cout << "Can't move." << std::endl;
		m_position.x = 20;
	}
	else if ( m_position.x > Screen::Instance()->GetResolution().x - m_images[m_state].GetSpriteDimension().x )
	{
		std::cout << "Can't move." << std::endl;
		m_position.x = Screen::Instance()->GetResolution().x - m_images[m_state].GetSpriteDimension().x;
	}
	else if (m_position.y < 65)
	{
		std::cout << "Can't move." << std::endl;
		m_position.y = 65;
	}
	else if (m_position.y > Screen::Instance()->GetResolution().y - m_images[m_state].GetSpriteDimension().y)
	{
		std::cout << "Can't move." << std::endl;
		m_position.y = Screen::Instance()->GetResolution().y - m_images[m_state].GetSpriteDimension().y;
	}
	else
	{
		m_position = m_position + m_direction;
	}

	//==========================================================
	//Spells Keys
	if (input->IsMouseClicked(HM_MOUSE_LEFT) && !m_isCasting && m_spellCoolDown >= 5.0)
	{
		m_spellCoolDown = 0;
		std::cout << "Spell cast." << std::endl;
		//m_spellCast.Play(0);
		m_spells.push_front(Spell(m_position, m_mousePosition));
		m_isCasting = true;
	}

	if (input->IsKeyPressed(HM_KEY_SPACE) && !m_isCasting && m_healingSpellCoolDown >= 5.0)
	{
		m_healingSpellCoolDown = 0;
		std::cout << "Healing Spell cast." << std::endl;
		m_Healspells.push_front(HealSpell(m_position));
		m_isCasting = true;
	}

	//==========================================================
	//Updating and checking Spells to Delete
	for (auto& spell : m_spells)
	{
		spell.Update();

		if (spell.GetPosition().x < 0 || spell.GetPosition().x > Screen::Instance()->GetResolution().x)
		{
			spell.IsAlive(false);
			m_isCasting = false;
			//spell.~Spell();
		}
		else if (spell.GetPosition().y < 0 || spell.GetPosition().y >= Screen::Instance()->GetResolution().y)
		{
			m_isCasting = false;
			spell.IsAlive(false);
			//spell.~Spell();
		}
	}
	
	auto CheckSpell = [&](const Spell& spell)
	{
		return !spell.IsAlive();
	};

	auto itS = std::remove_if(m_spells.begin(), m_spells.end(), CheckSpell);

	m_spells.erase(itS, m_spells.end());
	
	for (auto& healSpell : m_Healspells)
	{
		healSpell.Update();
		healSpell.SetPosition(this->GetPosition());

		if (healSpell.AnimationSpell())
		{
			healSpell.IsAlive(false);
			m_isCasting = false;
		}
	}

	auto CheckHealSpell = [&](const HealSpell& healSpell)
	{
		return !healSpell.IsAlive();
	};

	auto itHs = std::remove_if(m_Healspells.begin(), m_Healspells.end(), CheckHealSpell);

	m_Healspells.erase(itHs, m_Healspells.end());
	
	//==========================================================
	//==========================================================
	//==========================================================
	//Collision Detection
	m_collider.SetDimension(m_size.x, m_size.y);
	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.Update();

	//if (m_playerHpBar.GetSpriteDimension().x > 0)
	//{
	//	m_playerHpBar.SetSpriteDimension(m_playerHpBar.GetSpriteDimension().x - 1, m_playerHpBar.GetSpriteDimension().y);
	//}
	//if (m_playerHpBar.GetSpriteDimension().x > 0)
	//{
	//	m_playerMpBar.SetSpriteDimension(m_playerHpBar.GetSpriteDimension().x - 1, m_playerHpBar.GetSpriteDimension().y);
	//}

	//Update Spell & Cooldowns
	m_playerSpellHud.Update();
	m_spellCoolDown += 0.1f;
	m_healingSpellCoolDown += 0.1f;
}

void Player::Render()
{
	m_images[m_state].Render(m_position.x, m_position.y, m_angle);

	for (auto& spell : m_spells)
	{
		spell.Render();
	}

	for (auto& spell : m_Healspells)
	{
		spell.Render();
	}

	m_playerHpBar.Render(69, 9, m_angle);
	m_playerMpBar.Render(69, 33, m_angle);
	m_playerSpellHud.Render(-10, -9, m_angle);
	m_necromancerHud.Render(6, -1, m_angle);
	m_playerHud.Render(1, 0, m_angle);
}