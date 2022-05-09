#include "PlayState.h"
#include "MenuState.h"

bool PlayState::OnEnter()
{
	//Load assets for player and enemy
	m_player.IsVisible(true);
	m_player.SetPosition(100, 200);
	m_player.SetAngle(0.0);
	m_player.SetSize(60, 100);
	m_player.SetVelocity(5);

	m_enemy.SetPosition(500, 200);
	m_enemy.SetSize(60, 100);
	//Load all music for game 
	Game::GetMusic().Load("Assets/Music/background_music.mp3");
	Game::GetMusic().Play(Music::PlayLoop::PLAY_ENDLESS);
	//Load images and fonts
	return true;
}

GameState* PlayState::Update()
{
	//auto screen = Game::GetScreen();
	auto input = Input::Instance();
	//Check keypress and mouse clicks
	//check if buttons are clicked on
	//All main game mechanics are updated here
	if (m_player.GetCollider().IsColliding(m_enemy.GetCollider()) && m_time > 2.0)
	{
		std::cout << "COLLISION" << std::endl;
		m_player.ReceiveDamage(m_enemy.GetDamage());
		m_time = 0;
	}
	else
	{
		std::cout << "NO COLLISION" << std::endl;
		std::cout << m_player.GetHealthPoints() << std::endl;
	}

	for (auto& spell : m_player.GetSpells())
	{
		if (spell.GetCollider().IsColliding(m_enemy.GetCollider()))
		{
			m_enemy.Respawn(rand() % (1100 - m_enemy.GetSize().x), (rand() % (690 - m_enemy.GetSize().y)));
		}
	}
	
	//If user press ESC > EXIT GAME
	if (input->IsKeyPressed(HM_KEY_ESCAPE))
	{
		return new MenuState;
	}

	m_enemy.FlipToPlayer(m_player.GetPosition());

	m_background.Update();
	m_player.Update();
	m_enemy.Update();

	m_time += 0.02f;
	std::cout << m_time << std::endl;
	return this;
}

bool PlayState::Render()
{
	//render background
	m_background.Render();
	
	//Render player
	if (m_player.IsVisible())
	{
		m_player.Render();
	}
	//render enemy
	m_enemy.Render();
	//render ...

	return true;
}

void PlayState::OnExit()
{
	//unload all music, text, sprites for this state
	Game::GetMusic().Unload();
	m_player.~Player();
	m_enemy.~Enemy();
	m_background.~Background();
}