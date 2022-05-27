#pragma once
#include <iostream>
#include <vector>

#include "Button.h"
#include "Background.h"
#include "GameState.h"
#include "OptionsState.h"
#include "PlayState.h"
#include "Screen.h"
#include "SliderButton.h"
#include "Sprite.h"

class MenuState : public GameState
{
public:

	~MenuState() override {}

	bool Render() override;
	bool OnEnter() override;
	void OnExit() override;
	
	GameState* Update() override;

private:

	Background m_background;
	std::vector<Button> m_buttons;
	Vector<int> m_buttonPos{ Screen::Instance()->GetResolution().x / 2, 200 };
};