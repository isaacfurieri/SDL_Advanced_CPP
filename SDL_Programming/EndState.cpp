#include "EndState.h"

EndState::EndState(EndState::State endState)
{
	m_endState = endState;

	if (m_endState == 0)
	{
		m_background.Load("GameEnd", "TheDevilTower");
	}
	else
	{
		m_background.Load("GameEndWin", "TheDevilTower");
	}
}

bool EndState::Render()
{
	m_background.Render();

	for (auto& button : m_buttons)
	{
		button.Render();
	}
	return false;
}

bool EndState::OnEnter()
{
	Vector<int> buttonPos = { Screen::Instance()->GetResolution().x / 2, 350 };

	m_buttons.push_back(Button("Menu"));
	m_buttons.push_back(Button("Play"));
	m_buttons.push_back(Button("Exit"));

	for (auto& button : m_buttons)
	{
		button.SetPosition(buttonPos);
		buttonPos.y += 100;
	}

	return true;
}

void EndState::OnExit()
{
}

GameState* EndState::Update()
{
	m_background.Update();

	for (auto& button : m_buttons)
	{
		auto tag = button.GetTag();
		button.Update();

		if (button.GetState() == Button::ButtonState::Hover)
		{
		}

		if (button.GetState() == Button::ButtonState::Clicked)
		{
			if (tag == "Play")
			{
				return new PlayState;
			}
			if (tag == "Menu")
			{
				return new MenuState;
			}
			if (tag == "Exit")
			{
				return nullptr;
			}
		}
	}
	return this;
}
