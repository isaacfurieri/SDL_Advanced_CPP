#pragma once
#include <iostream>
#include <vector>

#include "Button.h"
#include "SliderButton.h"
#include "GameState.h"
#include "PlayState.h"
#include "OptionsState.h"
#include "Sound.h"
#include "Sprite.h"
#include "Screen.h"

class MenuState : public GameState
{
public:

	~MenuState() override {}

	bool Render() override;
	bool OnEnter() override;
	void OnExit() override;
	
	GameState* Update() override;

private:

	bool isOver{ false };

	std::vector<Button> buttons;
	Vector<int> buttonPos{ Screen::Instance()->GetResolution().x / 2, 100 };
};