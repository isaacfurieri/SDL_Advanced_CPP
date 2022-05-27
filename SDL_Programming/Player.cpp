#include "Player.h"

Player::Player()
{
	//==========================================================
	//LOADING ASSETS
	//==========================================================
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
		m_images[i].SetSpriteDimension(75, 75);
		m_images[i].IsAnimated(true);
		m_images[i].SetAnimationVelocity(0.5f);
		m_images[i].SetImageDimension(9, 1, 360, 40);
	}

	m_playerSpellHud.Load("Assets/Images/Character/Info/SpellHud.png");
	m_playerSpellHud.SetImageDimension(10, 9, 1000, 900);
	m_playerSpellHud.IsAnimationLooping(true);
	m_playerSpellHud.IsAnimated(true);
	m_playerSpellHud.SetAnimationVelocity(5.0f);
	m_playerSpellHud.SetSpriteDimension(95, 95);


	m_necromancerHud.Load("Assets/Images/Character/Info/NecromancerHud.png");
	m_necromancerHud.SetImageDimension(1, 1, 67, 55);
	m_necromancerHud.SetSpriteDimension(63, 55);

	m_playerHud.Load("Assets/Images/Character/Info/PlayerHud.png");
	m_playerHud.SetImageDimension(1, 1, 273, 74);
	m_playerHud.SetSpriteDimension(280, 75);

	m_playerHpBar.Load("Assets/Images/Character/Info/PlayerHpBar.png");
	m_playerHpBar.SetImageDimension(1, 1, 174, 24);
	m_playerHpBar.SetSpriteDimension(187, 24);
	m_maxHealthBarSize = m_playerHpBar.GetSpriteDimension().x;

	m_playerMpBar.Load("Assets/Images/Character/Info/PlayerMpBar.png");
	m_playerMpBar.SetImageDimension(1, 1, 206, 24);
	m_playerMpBar.SetSpriteDimension(208, 24);
	m_maxManaBarSize = m_playerMpBar.GetImageDimension().x;
	//==========================================================
	//Sounds
	//==========================================================
	//Character Setup
	m_maxHealthPoints = 150;
	m_maxManaPoints = 150;
	m_healthPoints = m_maxHealthPoints;
	m_manaPoints = m_maxManaPoints;
	m_damage = 10;
	m_loseHealth = 0;
	//==========================================================
	//Collision
	//==========================================================
	m_collider.SetDimension(75, 75);
	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.Update();
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
	//m_spells.~deque();
	m_Healspells.~deque();
	Game::GetSound().Unload();
}

int Player::GetDamage() const
{
	return m_damage;
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

	SetLooseHealth(monsterDamage);
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

void Player::SetLooseHealth(int looseHealth)
{
	m_loseHealth += looseHealth;
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

Sprite Player::GetImages() const
{
	return m_images[m_state];
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

//std::deque<Spell> Player::GetSpells()
//{
//	return m_spells;
//}

Spell* Player::GetSpellPtr()
{
	return m_fireballSpell;
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
	else if (m_position.x > Screen::Instance()->GetResolution().x - m_images[m_state].GetSpriteDimension().x)
	{
		std::cout << "Can't move." << std::endl;
		m_position.x = Screen::Instance()->GetResolution().x - m_images[m_state].GetSpriteDimension().x;
	}
	else if (m_position.y < 15)
	{
		std::cout << "Can't move." << std::endl;
		m_position.y = 15;
	}
	else if (m_position.y > Screen::Instance()->GetResolution().y - m_images[m_state].GetSpriteDimension().y)
	{
		std::cout << "Can't move." << std::endl;
		m_position.y = Screen::Instance()->GetResolution().y - m_images[m_state].GetSpriteDimension().y;
	}
	else
	{
		m_position = m_position + m_direction;
		Game::GetSound().Play(0);
	}

	//==========================================================
	//Spells Keys
	if (input->IsMouseClicked(HM_MOUSE_LEFT) && !m_isCasting && m_spellCoolDown >= 5.0)
	{
		m_spellCoolDown = 0;
		std::cout << "Spell cast." << std::endl;
		//m_spellCast.Play(0);
		//m_spells.push_front(Spell(m_position, m_mousePosition));
		m_fireballSpell = new Spell(m_position, m_mousePosition);
		m_isCasting = true;
	}

	if (input->IsKeyPressed(HM_KEY_SPACE) && !m_isCasting && m_healingSpellCoolDown >= 10.0)
	{
		m_healingSpellCoolDown = 0;
		std::cout << "Healing Spell cast." << std::endl;
		m_Healspells.push_front(HealSpell(m_position));
		m_isCasting = true;
	}
	//TODO - Multiple Spells Cast
	/*for (auto& spell : m_spells)
	{
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
		if (spell.IsAlive())
		{
			spell.Update();
		}
	}
	auto CheckSpell = [&](const Spell& spell)
	{
		return !spell.IsAlive();
	};

	auto itS = std::remove_if(m_spells.begin(), m_spells.end(), CheckSpell);

	m_spells.erase(itS, m_spells.end());

	*/
	//==========================================================
	//Updating and checking Spell Deque to Delete, Cooldowns
	for (auto& healSpell : m_Healspells)
	{
		healSpell.SetPosition(this->GetPosition());
		if (healSpell.IsAlive())
		{
			healSpell.Update();
		}
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

	if (m_fireballSpell)
	{
		if (m_fireballSpell->GetPosition().x < 0 || m_fireballSpell->GetPosition().x > Screen::Instance()->GetResolution().x)
		{
			m_fireballSpell->IsAlive(false);
			m_fireballSpell->IsActive(false);
			m_isCasting = false;
		}
		else if (m_fireballSpell->GetPosition().y < 0 || m_fireballSpell->GetPosition().y >= Screen::Instance()->GetResolution().y)
		{
			m_isCasting = false;
			m_fireballSpell->IsAlive(false);
			m_fireballSpell->IsActive(false);
		}
		if (m_fireballSpell->GetImage().IsAnimationDead())
		{
			m_fireballSpell->~Spell();
			m_isCasting = false;
		}
		m_fireballSpell->Update();
	}

	//==========================================================
	//Cooldown
	m_playerSpellHud.Update();
	m_spellCoolDown += 0.1f;
	m_healingSpellCoolDown += 0.1f;
	//==========================================================
	//Collision Detection
	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.Update();
	//==========================================================
	//HP Bar and HUD
	if (m_playerHpBar.GetSpriteDimension().x > 0 && m_loseHealth > 0)
	{
		m_playerHpBar.SetSpriteDimension(m_playerHpBar.GetSpriteDimension().x - 1, m_playerHpBar.GetSpriteDimension().y);
		SetLooseHealth(-1);
	}
	//==========================================================
}

void Player::Render()
{
	m_images[m_state].Render(m_position.x, m_position.y, m_angle);

	/* //render deque of spells
	for (auto& spell : m_spells)
	{
		spell.Render();
	}*/

	for (auto& healSpell : m_Healspells)
	{
		healSpell.Render();
	}

	if (m_fireballSpell && m_fireballSpell->IsActive())
	{
		m_fireballSpell->Render();
	}

	m_playerHpBar.Render(69, 9, m_angle);
	m_playerMpBar.Render(69, 33, m_angle);
	m_playerSpellHud.Render(-10, -9, m_angle);
	m_necromancerHud.Render(6, -1, m_angle);
	m_playerHud.Render(1, 0, m_angle);
	m_collider.Render();
}