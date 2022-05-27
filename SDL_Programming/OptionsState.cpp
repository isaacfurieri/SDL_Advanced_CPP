#include "OptionsState.h"

bool OptionsState::OnEnter()
{
	m_sliders.push_back(SliderButton("MusicSlider"));
	m_sliders.push_back(SliderButton("SoundSlider"));

	for (auto& slider : m_sliders)
	{
		slider.SetPosition(m_buttonPos);
		m_buttonPos.y += 100;
	}

	m_buttons.push_back(Button("Back"));

	for (auto& button : m_buttons)
	{
		button.SetPosition(m_buttonPos);
		m_buttonPos.y += 100;
	}
	//TODO SAVE MUSIC AND SOUD VOLUME VALUES WHEN USING SLIDERS AND APPLY IN ALL GAME STATES.
	//Music
	//Game::GetMusic().Load("Assets/Music/TheDevilTower.mp3");
	//Game::GetMusic().Play(Music::PlayLoop::PLAY_ENDLESS);

	return true;
}

GameState* OptionsState::Update()
{
	static float time = 0.0f;

	for (auto& slider : m_sliders)
	{
		auto tag = slider.GetTag();

		slider.Update();
		slider.Render();

		if (slider.GetState() == SliderButton::SliderState::Hover)
		{
		}

		if (slider.GetState() == SliderButton::SliderState::Clicked && time > 2.0)
		{
			if (tag == "SoundSlider")
			{
				time = 0.0f;
				slider.SetSliderPinPosition();

				auto volume = static_cast<int>(slider.GetSliderValue() / 2);

				//Volume min-max is 0-128 on SDL library.
				if (volume < 0)
				{
					volume = 0;
					//Game::GetSound().SetVolume(volume);
				}
				else if (volume > 128)
				{
					volume = 128;
					//Game::GetSound().SetVolume(volume);
				}
				else
				{
					//Game::GetSound().SetVolume(volume);
				}
			}
			if (tag == "MusicSlider")
			{
				time = 0.0f;
				slider.SetSliderPinPosition();

				auto volume = static_cast<int>(slider.GetSliderValue() / 2);

				//Volume min-max is 0-128 on SDL library.
				if (volume < 0)
				{
					volume = 0;
					//Game::GetMusic().SetVolume(volume);
				}
				else if (volume > 128)
				{
					volume = 128;
					//Game::GetMusic().SetVolume(volume);
				}
				else
				{
					//Game::GetMusic().SetVolume(volume);
				}
			}
		}

		time += 0.1f;
	}

	for (auto& button : m_buttons)
	{
		auto tag = button.GetTag();

		button.Update();
		button.Render();

		if (button.GetState() == Button::ButtonState::Hover)
		{
		}

		if (button.GetState() == Button::ButtonState::Clicked && time > 2.0)
		{
			if (Input::Instance()->GetMouseButtonUp())
			{
				if (tag == "Back")
				{
					time = 0.0f;
					return new MenuState;
				}
			}
		}
	}
	return this;
}

bool OptionsState::Render()
{
	for (auto& slider : m_sliders)
	{
		slider.Render();
	}
	for (auto& button : m_buttons)
	{
		button.Render();
	}
	return false;
}

void OptionsState::OnExit()
{
	for (auto& slider : m_sliders)
	{
		slider.Shutdown();
	}
	for (auto& button : m_buttons)
	{
		button.Shutdown();
	}
	m_sliders.clear();
	m_buttons.clear();
}