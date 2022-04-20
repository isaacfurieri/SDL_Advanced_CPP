#include "Player.h"

Player::Player()
{
	m_images[Idle].Load("Assets/Images/Character/Necromancer/necromancer_idle.png");
	m_images[MovingUp].Load("Assets/Images/Character/Necromancer/necromancer_moving_up.png");
	m_images[MovingDown].Load("Assets/Images/Character/Necromancer/necromancer_moving_down.png");
	m_images[MovingLeft].Load("Assets/Images/Character/Necromancer/necromancer_moving_left.png");
	m_images[MovingRight].Load("Assets/Images/Character/Necromancer/necromancer_moving_right.png");
	m_images[CastingUp].Load("Assets/Images/Character/Necromancer/necromancer_casting_up2.png");
	m_images[CastingDown].Load("Assets/Images/Character/Necromancer/necromancer_casting_down2.png");
	m_images[CastingLeft].Load("Assets/Images/Character/Necromancer/necromancer_casting_left.png");
	m_images[CastingRight].Load("Assets/Images/Character/Necromancer/necromancer_casting_right.png");

	for (int i = 0; i < TotalStates; i++)
	{
		m_images[i].IsAnimationLooping(true);
		m_images[i].SetSpriteDimension(100, 100);
		m_images[i].IsAnimated(true);
		m_images[i].SetAnimationVelocity(0.5f);

		if (i == Idle || i == MovingUp || i == MovingDown || i == MovingLeft || i == MovingRight)
		{
			m_images[i].SetImageDimension(9, 1, 315, 35);
		}
		else
		{
			m_images[i].SetImageDimension(9, 1, 360, 40);
		}
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

	m_playerMpBar.Load("Assets/Images/Character/Hud/PlayerMpBar.png");
	m_playerMpBar.SetImageDimension(1, 1, 206, 24);
	m_playerMpBar.SetSpriteDimension(208, 24);

	//m_image.SetSpriteDimension(200, 257);
	//m_image.SetImageDimension(10, 1, 5880, 600);

	//m_image.SetAnimationVelocity(4.5f);

	//m_spellCast.Load("Assets/Music/fireball_cast.wav");
	m_footSteps.Load("Assets/Music/footsteps_walking.wav");
}

Player::~Player()
{
	for (int i = 0; i < TotalStates; i++)
	{
		m_images[i].Unload();
	}
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
	return isCasting;
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
		if (isCasting)
		{
			m_state = castingState;
		}
		else if (!isCasting)
		{
			m_state = movingState;
			std::cout << direction.x << std::endl;
		}
		m_direction = direction;
	};

	//TODO -- DIAGONAL MOVEMENTS IF PRESSING TWO BUTTONS

	if (input->IsKeyPressed(HM_KEY_RIGHT))
	{
		ChangeStateAndDir(CastingRight, MovingRight, Vector<int>(1, 0));
	}
	else if (input->IsKeyPressed(HM_KEY_LEFT))
	{
		ChangeStateAndDir(CastingLeft, MovingLeft, Vector<int>(-1, 0));
	}
	else if (input->IsKeyPressed(HM_KEY_UP))
	{
		ChangeStateAndDir(CastingUp, MovingUp, Vector<int>(0, -1));
	}
	else if (input->IsKeyPressed(HM_KEY_DOWN)) 
	{
		ChangeStateAndDir(CastingDown, MovingDown, Vector<int>(0, 1));
	}
	else if (input->IsKeyPressed(HM_KEY_D))
	{
		ChangeStateAndDir(CastingRight, MovingRight, Vector<int>(1, 0));
	}
	else if (input->IsKeyPressed(HM_KEY_A))
	{
		ChangeStateAndDir(CastingLeft, MovingLeft, Vector<int>(-1, 0));
	}
	else if (input->IsKeyPressed(HM_KEY_W))
	{
		ChangeStateAndDir(CastingUp, MovingUp, Vector<int>(0, -1));
	}
	else if (input->IsKeyPressed(HM_KEY_S))
	{
		ChangeStateAndDir(CastingDown, MovingDown, Vector<int>(0, 1));
	}
	else
	{
		ChangeStateAndDir(CastingDown, Idle, Vector<int>(0, 0));
	}


	//==========================================================
	
	static float time = 0.0f;

	if (input->IsMouseClicked(HM_MOUSE_LEFT) && !isCasting && time >= 1.0f)
	{
		std::cout << "Spell cast." << std::endl;
		//m_spellCast.Play(0);
		m_spells.push_front(Spell(m_position, m_mousePosition));
		isCasting = true;
	}

		//delete m_spell;
		//m_spell = nullptr;

	//==========================================================
	
	//timer for 10 secs
	std::cout << time << std::endl;
	time += 0.1f;
	//switch isCasting = false;
	

	if (time >= 10.0f && !m_spells.empty())
	{
		isCasting = false;
		m_spells.pop_back();
		time = 0.0f;
	}

	//==========================================================

	for (auto& spell : m_spells)
	{
		spell.Update();

		if (spell.GetPosition().x < 0 || Screen::Instance()->GetResolution().x)
		{
			spell.IsAlive(false);

		}
		else if (spell.GetPosition().y < 0 || spell.GetPosition().y >= Screen::Instance()->GetResolution().y)
		{
			spell.IsAlive(false);
		}
	}

	//==========================================================
	
	m_direction = m_direction * m_velocity;

	if (m_position.x < 20) 
	{
		//Do not move
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

	//m_position = m_position + m_direction;
	
	m_images[m_state].Update();

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

	//Update Spell
	m_playerSpellHud.Update();
}

void Player::Render()
{
	m_images[m_state].Render(m_position.x, m_position.y, m_angle);

	for (auto& spell : m_spells)
	{
		spell.Render();
	}

	m_playerHpBar.Render(69, 9, m_angle);
	m_playerMpBar.Render(69, 33, m_angle);
	m_playerSpellHud.Render(-10, -9, m_angle);
	m_necromancerHud.Render(6, -1, m_angle);
	m_playerHud.Render(1, 0, m_angle);
}