#include "OptionsState.h"

bool OptionsState::OnEnter()
{
	sliders.push_back(SliderButton("SliderBar", "SliderPin"));

	for (auto& slider : sliders)
	{
		slider.SetPosition(buttonPos);
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

			if (tag == "SliderBar")
			{
				slider.SetSliderPinPosition();
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

	return false;
}

void OptionsState::OnExit()
{
}