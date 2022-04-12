#include<dos.h>

#include "MenuState.h"

bool MenuState::OnEnter()
{

	buttons.push_back(Button("Menu"));
	buttons.push_back(Button("Play"));
	//buttons.push_back(Button("Load"));
	buttons.push_back(Button("Options"));
	buttons.push_back(Button("Exit"));
	//buttons.push_back(Button("Resume"));

	for (auto& button : buttons)
	{
		button.SetPosition(buttonPos);
		buttonPos.y += 100;
	}

	sliders.push_back(SliderButton("SliderBar", "SliderPin"));

	for (auto& slider : sliders)
	{
		slider.SetPosition(buttonPos);
		buttonPos.y += 100;
	}
	//Load assets for menu buttons
	//All Button Sprites
	//m_buttonSprites.Load("Assets/Menu/MenuButtons2.png");
	//m_buttonSprites.SetImageDimension(2, 13, 1200, 2600);
	//m_buttonSprites.SetImageCel(2, 4);
	//m_buttonSprites.SetSpriteDimension(150, 75);

	//Load menu background music

	Game::GetMusic().Load("Assets/Music/TheDevilTower.mp3");
	Game::GetMusic().SetVolume(15);
	Game::GetMusic().Play(Music::PlayLoop::PLAY_ENDLESS);
	//Load backdrop image
	//Load Music
	//m_isClickedMusic.Initialize();
	//m_isOverMusic.Initialize();

	return true;
}

GameState* MenuState::Update()
{
	for (auto& button : buttons)
	{
		auto tag = button.GetTag();
		
		button.Update();
		button.Render();

		if (button.GetState() == Button::ButtonState::Hover)
		{
		}

		if (button.GetState() == Button::ButtonState::Clicked)
		{

			if (tag == "Play")
			{
				return new PlayState;
			}
			if (tag == "Options")
			{
				return new OptionsState;
			}
			if (tag == "Exit")
			{
				return nullptr;
			}
		}
	}

	for (auto& slider : sliders)
	{
		auto tag = slider.GetTag();

		slider.Update();
		slider.Render();

		if (slider.GetState() == SliderButton::SliderState::Hover)
		{
		}

		if (slider.GetState() == SliderButton::SliderState::Clicked)
		{

			if (tag == "SliderBar")
			{
				slider.SetSliderPinPosition();
			}
		}
	}



	//if (SDL_HasIntersection(&mousePos, &exitButtonPos) && isOver == false)
	//{
	//	m_isOverMusic.Play(Music::PlayLoop::PLAY_ONCE);
	//	m_isOverMusic.Play(1);
	//	isOver = true;
	//	m_buttonSprites.SetImageCel(1, 4);
	//	std::cout << "Mouse is Colliding" << std::endl;
	//}
	//else if (!SDL_HasIntersection(&mousePos, &exitButtonPos))
	//{
	//	isOver = false;
	//	m_buttonSprites.SetImageCel(2, 4);
	//}

	//if (isOver && Input::Instance()->IsMouseClicked())
	//{
	//	//m_isClickedMusic.Play(Music::PlayLoop::PLAY_ONCE);
	//	m_isClickedMusic.Play(1);
	//	Sleep(2500);
	//	return nullptr;
	//}
	
	//Check keypress and mouse clicks
	//check if buttons are clicked on
	//check if user scrolls up or down a menu
	/*
	if (userClicksPlayGameButton)
	{
		return new PlayState;
	}

	if (userClicksExitGameButton)
	Input::Instance()->
	{
		return nullptr;
	}
	*/
	return this;
}

bool MenuState::Render()
{
	for (auto& button : buttons)
	{
		button.Render();
	}

	for (auto& slider : sliders)
	{
		slider.Render();
	}

	return false;
}

void MenuState::OnExit()
{
	//unload all music, text, sprites for this state
	Game::GetMusic().Unload();
	//m_isClickedMusic.Unload();
	//m_isOverMusic.Unload();
}