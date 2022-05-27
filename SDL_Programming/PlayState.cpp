#include "PlayState.h"

void PlayState::Door(bool door)
{
	m_boolAnimation = door;
}

bool PlayState::OnEnter()
{
	m_background.Load("BigRoom", "background_music");

	//Load assets for player and enemy
	m_player.IsVisible(true);
	m_player.SetPosition(100, 200);
	m_player.SetAngle(0.0);
	m_player.SetSize(60, 100);
	m_player.SetVelocity(5);

	m_enemy.SetPosition(500, 200);
	m_enemy.SetSize(60, 100);

	m_doorAnimation.Load("Assets/Images/Background/OpeningDoor.png");
	m_doorAnimation.SetImageDimension(8, 1, 304, 42);
	m_doorAnimation.IsAnimationLooping(false);
	m_doorAnimation.IsAnimated(false);
	m_doorAnimation.SetAnimationVelocity(0.05f);
	m_doorAnimation.SetSpriteDimension(60, 50);

	m_doorOpening.Load("Assets/Music/ScaryWoodenDoorOpening.wav");
	m_doorOpening.SetVolume(30);

	//Load Score
	m_score.SetPosition(10, 50);
	m_score.SetScore(0);

	m_gameFinished = 0;
	return true;
}

GameState* PlayState::Update()
{
	//All main game mechanics are updated here
	//==========================================================
	auto input = Input::Instance();

	//Collision & Damage
	if (m_player.GetCollider().IsColliding(m_enemy.GetCollider()) && m_time > 2.0 && m_gameFinished <= 0)
	{
		std::cout << "COLLISION" << std::endl;
		if (m_enemy.IsAlive())
		{
			m_player.ReceiveDamage(m_enemy.GetDamage());
		}
		m_enemy.SetState(Enemy::State::Attacking);
		m_time = 0;
	}
	if(!m_player.GetCollider().IsColliding(m_enemy.GetCollider()) && m_time > 1.0 && m_gameFinished <= 0)
	{
		m_enemy.SetState(Enemy::State::Moving);
	}
	//Spell ptr collider
	if (m_player.GetSpellPtr() && m_player.GetSpellPtr()->IsAlive() && m_player.GetSpellPtr()->GetCollider().IsColliding(m_enemy.GetCollider()) && m_timeMonster > 1.0 && m_gameFinished <= 0)
	{
		m_player.GetSpellPtr()->IsAlive(false);
		m_player.GetSpellPtr()->ChangeState(Spell::SpellState::Explosion);
		if (m_enemy.GetHealth() - m_player.GetDamage() <= 0 && m_enemy.IsAlive())
		{
			m_score.SetScore(10);
		}
		m_enemy.ReceiveDamage(m_player.GetDamage());
		m_enemy.SetState(Enemy::State::TakingHit);
		m_timeMonster = 0;
		m_time = 0;

		std::cout << m_enemy.GetHealth() << std::endl;
	}

	//==========================================================
	//Enemy Update
	Vector<int> centre;

	centre.x = m_player.GetPosition().x - m_player.GetImages().GetCentrePosition().x;
	centre.y = m_player.GetPosition().y - m_player.GetImages().GetCentrePosition().y;

	m_enemy.UpdateDirection(centre);
	m_enemy.FlipToPlayer(centre);


	m_time += 0.02f;
	m_timeMonster += 0.02f;
	
	//==========================================================
	//Game Level Update
	if (input->IsKeyPressed(HM_KEY_ESCAPE))
	{
		return new MenuState;
	}

	if (!m_player.IsAlive())
	{
		//GAME OVER SCREEN
		return new EndState(EndState::State::Lose);
	}
	if (!m_enemy.IsAlive())
	{
		m_enemy.SetState(Enemy::State::Death);
		m_gameFinished += 0.02f;
	}
	if (m_gameFinished > 5.0 && m_boolAnimation)
	{
		m_doorOpening.Play(0);
		m_doorAnimation.IsAnimated(m_boolAnimation);

		if (m_doorAnimation.IsAnimationDead())
		{
			m_doorAnimation.IsAnimationDead(!m_boolAnimation);
			m_doorAnimation.IsAnimated(!m_boolAnimation);
			m_doorAnimation.SetImageCel(8, 1);
			Door(!m_boolAnimation);
		}
	}
	if (m_player.GetPosition().x + m_player.GetImages().GetSpriteDimension(). x / 2 > 1110 && m_player.GetPosition().x + m_player.GetImages().GetSpriteDimension().x / 2 < 1160 && m_player.GetPosition().y < 20 && !m_boolAnimation)
	{
		//GAME WIN SCREEN
		return new EndState(EndState::State::Win);
	}

	//==========================================================
	//Updates
	m_background.Update();
	m_score.Update();
	m_doorAnimation.Update();
	m_enemy.Update();
	m_player.Update();
	return this;
}

bool PlayState::Render()
{
	//render background
	m_background.Render();
	m_doorAnimation.Render(1100, 03, 0.0);
	//Render player
	if (m_player.IsVisible())
	{
		m_player.Render();
	}
	//render enemy
	m_enemy.Render();
	//render score
	m_score.Render();
	return true;
}

void PlayState::OnExit()
{
	//unload all music, text, sprites for this state
	m_player.~Player();
	m_enemy.~Enemy();
	m_score.~Score();
}