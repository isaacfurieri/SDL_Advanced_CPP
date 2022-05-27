#pragma once
#include <iostream>

#include "GameObject.h"
#include "Sound.h"
#include "Sprite.h"

class Button :	public GameObject
{
public:

	enum class ButtonState
	{
		Default,
		Hover,
		Clicked
	};

	Button(const std::string& filename);

	const ButtonState& GetState() const;
	void Shutdown();

	virtual void Update();
	virtual void Render();

private:

	bool isHover{ false };

	ButtonState m_buttonState;
	SDL_Rect m_mousePosition, m_spritePosition;
	Sound m_sfxHover, m_sfxClicked;
	Sprite m_buttonSprite;
};

