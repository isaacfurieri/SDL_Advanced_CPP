#include "Player.h"

Player::Player()
{
	m_velocity = 0;
	m_spell = nullptr;
	isCasting = false;
	m_state = Idle;

	m_images[Idle].Load("Assets/Images/Character/Necromancer/necromancer_idle.png", Game::GetScreen());
	m_images[MovingUp].Load("Assets/Images/Character/Necromancer/necromancer_moving_up.png", Game::GetScreen());
	m_images[MovingDown].Load("Assets/Images/Character/Necromancer/necromancer_moving_down.png", Game::GetScreen());
	m_images[MovingLeft].Load("Assets/Images/Character/Necromancer/necromancer_moving_left.png", Game::GetScreen());
	m_images[MovingRight].Load("Assets/Images/Character/Necromancer/necromancer_moving_right.png", Game::GetScreen());
	m_images[CastingUp].Load("Assets/Images/Character/Necromancer/necromancer_casting_up2.png", Game::GetScreen());
	m_images[CastingDown].Load("Assets/Images/Character/Necromancer/necromancer_casting_down2.png", Game::GetScreen());
	m_images[CastingLeft].Load("Assets/Images/Character/Necromancer/necromancer_casting_left.png", Game::GetScreen());
	m_images[CastingRight].Load("Assets/Images/Character/Necromancer/necromancer_casting_right.png", Game::GetScreen());

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

void Player::Update(Input& input)
{
	//Manupulate/Read keys here, WASD, left up right down

	//UP DOWN LEFT RIGHT ARROW MOVIMENT
	
	if (input.GetKeyDown() == SDL_SCANCODE_RIGHT)
	{
		m_state = MovingRight;
		std::cout << "Right key pressed. Move player right." << std::endl;
		m_direction.x = 1;
		m_direction.y = 0;
		std::cout << m_direction.x << std::endl;
	}
	else if (input.GetKeyDown() == SDL_SCANCODE_LEFT)
	{
		std::cout << "Left key pressed. Move player left." << std::endl;
		m_state = MovingLeft;
		m_direction.x = -1;
		m_direction.y = 0;
	}
	else if (input.GetKeyDown() == SDL_SCANCODE_UP) {
		std::cout << "Up key pressed. Move player up." << std::endl;
		m_state = MovingUp;
		m_direction.x = 0;
		m_direction.y = -1;
	}
	else if (input.GetKeyDown() == SDL_SCANCODE_DOWN) {
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
	
	m_position = m_position.Add(m_direction);

	//WASD - Movement
	/*
	if (input.GetKeyDown() == SDLK_w || input.GetKeyDown() == SDLK_w && isCasting)
	{
		if (isCasting)
		{
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
	else if (input.GetKeyDown() == SDLK_a || input.GetKeyDown() == SDLK_a && isCasting)
	{
		if (isCasting)
		{
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
	else if (input.GetKeyDown() == SDLK_s || input.GetKeyDown() == SDLK_s && isCasting)
	{
		if (isCasting)
		{
			m_state = CastingDown;
			std::cout << "S key pressed while casting. Move player down with casting animation." << std::endl;
		}
		else
		{
			m_state = MovingDown;
			std::cout << "S key pressed. Move player down." << std::endl;
		}
		m_direction.x = 0;
		m_direction.y = 1;
	}
	else if (input.GetKeyDown() == SDLK_d || input.GetKeyDown() == SDLK_d && isCasting)
	{
		if (isCasting)
		{
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
	else
	{
		if (isCasting)
		{
			m_state = CastingDown;
			std::cout << "D key pressed while casting. Move player right with casting animation." << std::endl;
		}
		else
		{
			m_state = IDLE;
			std::cout << "D key pressed. Move player right." << std::endl;
		}
		m_direction.x = 0;
		m_direction.y = 0;
	}
	
	// Spells
	if (input.GetKeyDown() == SDLK_e) {
		std::cout << "E pressed. Shoot Fireball." << std::endl;
		m_spellCast.Play();
		isCasting = true;

		if (!m_spell)
		{
			//m_spellPosition = m_position.Add(m_images[m_state].GetSpriteDimension().Divide(2));
			m_spellPosition = m_position;
			m_mousePosition = input.GetMousePosition();
			m_spell = new Spell(Game::GetScreen(), m_spellPosition, m_mousePosition);
		}
	}
	else if (input.GetKeyUp() == SDLK_e)
	{
		isCasting = false;
		std::cout << "Spell Unload." << std::endl;
		delete m_spell;
		m_spell = nullptr;
	}

	m_direction = m_direction.Scale(m_velocity);

	if (m_position.x < 0)
	{
		//Do not move
		std::cout << "Can't move." << std::endl;
		m_position.x = m_position.x + 1;
	}
	else if (m_position.x > 1155)
	{
		std::cout << "Can't move." << std::endl;
		m_position.x = m_position.x - 1;
	}
	else if (m_position.y < 65)
	{
		std::cout << "Can't move." << std::endl;
		m_position.y = m_position.y + 1;
	}
	else if (m_position.y > 590)
	{
		std::cout << "Can't move." << std::endl;
		m_position.y = m_position.y - 1;
	}
	else
	{
		m_position = m_position.Add(m_direction);
	}

	m_images[m_state].Update();

	m_collider.SetDimension(m_size.x, m_size.y);
	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.Update();

	if (m_spell)
	{
		m_spell->Update(input);
	}*/
}	

void Player::Render(Screen& screen)
{
	m_images[m_state].Render(m_position.x, m_position.y, m_angle, Game::GetScreen());

	if (m_spell)
	{
		m_spell->Render(Game::GetScreen());
	}
}