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

	const SliderState& GetState() const;
	int GetSliderValue();
	void SetSliderPinPosition();
	void Shutdown();
	
	SDL_Rect GetPinPosition();
	
	SliderButton(const std::string& slidername);
	
	virtual void Update();
	virtual void Render();

private:

	bool m_isHover{ false }, m_sprite{ false };

	SDL_Rect m_mousePosition, m_sliderPosition, m_pinPosition;
	SliderState m_sliderState;
	Sprite m_sliderBar, m_sliderPin;
};

