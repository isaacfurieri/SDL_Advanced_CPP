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
		m_images[i].SetAnimationVelocity(1.5f);

		if (i == Idle || i == MovingUp || i == MovingDown || i == MovingLeft || i == MovingRight)
		{
			m_images[i].SetImageDimension(9, 1, 315, 35);
		}
		else
		{
			m_images[i].SetImageDimension(9, 1, 351, 38);
		}
	}

	//m_image.SetSpriteDimension(200, 257);
	//m_image.SetImageDimension(10, 1, 5880, 600);

	//m_image.SetAnimationVelocity(4.5f);

	m_spellCast.Load("Assets/Music/fireball_cast.wav");
	m_footSteps.Load("Assets/Music/footsteps_walking.wav");
}

Player::~Player()
{
	m_images[m_state].Unload();
}

void Player::SetVelocity(int velocity)
{
	m_velocity = velocity;
}

void Player::SetState(State state)
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
	if (input->IsKeyPressed(HM_KEY_RIGHT))
	{
		m_state = MovingRight;
		std::cout << "Right key pressed. Move player right." << std::endl;
		m_direction.x = 1;
		m_direction.y = 0;
		std::cout << m_direction.x << std::endl;
	}
	else if (input->IsKeyPressed(HM_KEY_LEFT))
	{
		std::cout << "Left key pressed. Move player left." << std::endl;
		m_state = MovingLeft;
		m_direction.x = -1;
		m_direction.y = 0;
	}
	else if (input->IsKeyPressed(HM_KEY_UP))
	{
		std::cout << "Up key pressed. Move player up." << std::endl;
		m_state = MovingUp;
		m_direction.x = 0;
		m_direction.y = -1;
	}
	else if (input->IsKeyPressed(HM_KEY_DOWN)) {
		std::cout << "Down key pressed. Move player down." << std::endl;
		m_state = MovingDown;
		m_direction.x = 0;
		m_direction.y = 1;
	}
	else
	{
		m_state = Idle;
		m_direction.x = 0;
		m_direction.y = 0;
	}


	//WASD - Movement
	//==========================================================
	/*
	if (input->IsKeyPressed(HM_KEY_W))
	{
		if (isCasting)
		{
			m_spellCast.Play();
			m_state = CastingUp;
			std::cout << "W key pressed while casting. Move player up with casting animation." << std::endl;
		}
		else
		{
			m_state = MovingUp;
			std::cout << "W key pressed. Move player up." << std::endl;
		}
		m_direction.x = 0;
		m_direction.y = -1;
	}
	else if (input->IsKeyPressed(HM_KEY_A) || input->IsKeyPressed(HM_KEY_A) && isCasting)
	{
		if (isCasting)
		{
			m_spellCast.Play();
			m_state = CastingLeft;
			std::cout << "A key pressed while casting. Move player left with casting animation." << std::endl;
		}
		else
		{
			m_state = MovingLeft;
			std::cout << "A key pressed. Move player left." << std::endl;
		}
		m_direction.x = -1;
		m_direction.y = 0;
	}
	else if (input->IsKeyPressed(HM_KEY_S) || input->IsKeyPressed(HM_KEY_S) && isCasting)
	{
		if (isCasting)
		{
			m_spellCast.Play();
			m_state = CastingDown;
			std::cout << "S key pressed while casting. Move player down with casting animation." << std::endl;
		}
		else
		{
			m_spellCast.Play();
			m_state = MovingDown;
			std::cout << "S key pressed. Move player down." << std::endl;
		}
		m_direction.x = 0;
		m_direction.y = 1;
	}
	else if (input->IsKeyPressed(HM_KEY_D) || input->IsKeyPressed(HM_KEY_D) && isCasting)
	{
		if (isCasting)
		{
			m_spellCast.Play();
			m_state = CastingRight;
			std::cout << "D key pressed while casting. Move player right with casting animation." << std::endl;
		}
		else
		{
			m_state = MovingRight;
			std::cout << "D key pressed. Move player right." << std::endl;
		}
		m_direction.x = 1;
		std::cout << m_direction.x << std::endl;
		m_direction.y = 0;
	}
	//==========================================================
	else
	{
		m_spellCast.Play();
		if (isCasting)
		{
			m_state = CastingDown;
			std::cout << "Player casting Idle." << std::endl;
		}
		else
		{
			m_state = Idle;
			std::cout << "Player Idle." << std::endl;
		}
		m_direction.x = 0;
		m_direction.y = 0;
	}
	
	*/
	//==========================================================
	// Spells
	//if (input->GetKeyDown() == SDLK_e) {
	//	std::cout << "E pressed. Shoot Fireball." << std::endl;
	//	m_spellCast.Play();
	//	isCasting = true;

	//	//if (!m_spell)
	//	//{
	//	//	//m_spellPosition = m_position.Add(m_images[m_state].GetSpriteDimension().Divide(2));
	//	//	m_spellPosition = m_position;
	//	//	m_mousePosition = input->GetMousePosition();
	//	//	m_spell = new Spell(m_spellPosition, m_mousePosition);
	//	//}
	//}
	
	//==========================================================
	

	if (input->IsMouseClicked(HM_MOUSE_LEFT) && !isCasting)
	{
		// IsKeyPressed(HM_KEY_E)
		std::cout << "Spell cast." << std::endl;
		m_spells.push_front(Spell(m_position, m_mousePosition));
		isCasting = true;
	}

		//delete m_spell;
		//m_spell = nullptr;

	//==========================================================
	
	//timer for 10 secs
	static float time = 0.0f;
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

}

void Player::Render()
{
	m_images[m_state].Render(m_position.x, m_position.y, m_angle);

	for (auto& spell : m_spells)
	{
		spell.Render();
	}
}