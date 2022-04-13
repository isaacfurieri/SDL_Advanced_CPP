#include "OptionsState.h"

bool OptionsState::OnEnter()
{
	sliders.push_back(SliderButton("MusicSlider"));
	sliders.push_back(SliderButton("SoundSlider"));

	for (auto& slider : sliders)
	{
		slider.SetPosition(buttonPos);
		buttonPos.y += 100;
	}

	buttons.push_back(Button("Back"));

	for (auto& button : buttons)
	{
		button.SetPosition(buttonPos);
		buttonPos.y += 100;
	}
	//Music
	Game::GetMusic().Load("Assets/Music/TheDevilTower.mp3");
	Game::GetMusic().Play(Music::PlayLoop::PLAY_ENDLESS);

	return true;
}

GameState* OptionsState::Update()
{
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
			if (tag == "SoundSlider")
			{
				slider.SetSliderPinPosition();

				auto volume = static_cast<int>( slider.GetSliderValue() / 2);

				//Volume min-max is 0-128 on SDL library.
				if (volume < 0)
				{
					volume = 0;
					Game::GetSound().SetVolume(volume);
				}
				else if (volume > 128)
				{
					volume = 128;
					Game::GetSound().SetVolume(volume);
				}
				else
				{
					Game::GetSound().SetVolume(volume);
				}
			}
			if (tag == "MusicSlider")
			{
				slider.SetSliderPinPosition();

				auto volume = static_cast<int>(slider.GetSliderValue() / 2);
				
				//Volume min-max is 0-128 on SDL library.
				if (volume < 0)
				{
				volume = 0;
				Game::GetMusic().SetVolume(volume);
				}
				else if (volume > 128)
				{
					volume = 128;
					Game::GetMusic().SetVolume(volume);
				}
				else
				{
					Game::GetMusic().SetVolume(volume);
				}
			}
		}
	}

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
			if (Input::Instance()->GetMouseButtonUp())
			{
				if (tag == "Back")
				{
					return new MenuState;
				}
			}

		}
	}

	return this;
}

bool OptionsState::Render()
{
	for (auto& slider : sliders)
	{
		slider.Render();
	}

	for (auto& button : buttons)
	{
		button.Render();
	}

	return false;
}

void OptionsState::OnExit()
{
	Game::GetMusic().Unload();
}