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
	static float time = 0.0f;

	for (auto& slider : sliders)
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
				time = 0.0f;
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

		time += 0.1f;
	}

	for (auto& button : buttons)
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
	for (auto& slider : sliders)
	{
		slider.Shutdown();
	}

	for (auto& button : buttons)
	{
		button.Shutdown();
	}

	sliders.clear();
	buttons.clear();

	Game::GetMusic().Unload();
}