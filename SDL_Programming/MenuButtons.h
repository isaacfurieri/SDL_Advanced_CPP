#pragma once
#include <vector>

#include "Game.h"
#include "GameObject.h"
#include "Sprite.h"
#include "Screen.h"

class MenuButtons : public GameObject
{

public:

	enum class ButtonState
	{
		MouseOut,
		MouseOver,
		Clicked
	};

	enum ButtonName
	{
		Play,
		Resume,
		Settings,
		Exit,
		Back,
		TotalButtons
	};

	MenuButtons();

	virtual void Update(Input* input);
	virtual void Render(Screen& screen);

private:

	Sprite m_image[ButtonName::TotalButtons];

};

