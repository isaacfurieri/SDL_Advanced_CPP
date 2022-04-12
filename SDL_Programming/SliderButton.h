#pragma once
#include <iostream>

#include "GameObject.h"
#include "Sound.h"
#include "Sprite.h"

class SliderButton : public GameObject
{
public:

	enum class SliderState
	{
		Default,
		Hover,
		Clicked
	};

	SliderButton(const std::string& sliderBarFileName, const std::string& sliderPinFilename);
	const SliderState& GetState() const;
	SDL_Rect GetPinPosition();
	void SetSliderPinPosition();
	virtual void Update();
	virtual void Render();

private:
	bool isHover{ false }, m_sprite{ false };
	SliderState m_sliderState;
	SDL_Rect m_mousePosition, m_sliderPosition, m_pinPosition;
	Sprite m_sliderBar, m_sliderPin;
};

