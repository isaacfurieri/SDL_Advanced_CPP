#include "OptionsState.h"

bool OptionsState::OnEnter()
{
	sliders.push_back(SliderButton("MusicSlider"));

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
			if (tag == "MusicSlider")
			{
				slider.SetSliderPinPosition();
				Game::GetMusic().SetVolume(slider.GetSliderValue());
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
}