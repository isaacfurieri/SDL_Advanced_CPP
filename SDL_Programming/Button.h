#pragma once
#include <string>

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

	virtual void Update();
	virtual void Render();

private:
	
	ButtonState m_buttonState;
	SDL_Rect m_mousePosition, m_spritePosition;
	Sound sfxOver, sfxClicked;
	Sprite m_buttonSprite;
};

