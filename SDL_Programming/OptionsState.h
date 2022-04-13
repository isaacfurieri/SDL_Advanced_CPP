#pragma once
#include <vector>

#include "Button.h"
#include "Game.h"
#include "GameState.h"
#include "MenuState.h"
#include "SliderButton.h"
#include "Sprite.h"

class OptionsState : public GameState
{
public:

	~OptionsState() override {}

	bool OnEnter() override;
	bool Render() override;
	void OnExit() override;

	GameState* Update() override;

private:

	std::vector<Button> buttons;
	std::vector<SliderButton> sliders;

	Vector<int> buttonPos{ 565, 100 };
};