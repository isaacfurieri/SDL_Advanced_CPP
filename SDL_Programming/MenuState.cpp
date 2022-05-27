#include<dos.h>

#include "MenuState.h"

bool MenuState::OnEnter()
{
	m_background.Load("MainMenu", "TheDevilTower");

	m_buttons.push_back(Button("Play"));
	m_buttons.push_back(Button("Options"));
	m_buttons.push_back(Button("Exit"));

	for (auto& button : m_buttons)
	{
		button.SetPosition(m_buttonPos);
		m_buttonPos.y += 100;
	}
	return true;
}

GameState* MenuState::Update()
{
	m_background.Update();
	static float time = 0.0f;

	for (auto& button : m_buttons)
	{
		auto tag = button.GetTag();

		button.Update();

		if (button.GetState() == Button::ButtonState::Hover)
		{
		}
		if (button.GetState() == Button::ButtonState::Clicked && time >= 2.0f)
		{
			if (tag == "Play")
			{
				time = 0.0;
				return new PlayState;
			}
			if (tag == "Options")
			{
				time = 0.0;
				return new OptionsState;
			}
			if (tag == "Exit")
			{
				time = 0.0;
				return nullptr;
			}
		}
	}
	time += 0.1f;
	return this;
}

bool MenuState::Render()
{
	m_background.Render();

	for (auto& button : m_buttons)
	{
		button.Render();
	}
	return false;
}

void MenuState::OnExit()
{
	for (auto& button : m_buttons)
	{
		button.Shutdown();
	}
	m_buttons.clear();
}