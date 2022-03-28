#pragma once
#include <vector>

#include "Game.h"
#include "GameObject.h"
#include "Sprite.h"

class MenuButtons : public GameObject
{

public:

	MenuButtons();

	virtual void Update();
	virtual void Render();

private:

	bool m_isClicked;
	bool m_isOver;
	SDL_Rect m_spritePosition;
	Sprite m_buttonSprite;

};

