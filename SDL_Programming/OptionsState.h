#pragma once
#include <vector>

#include "Button.h"
#include "Game.h"
#include "GameState.h"
#include "MenuState.h"
#include "Sound.h"
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

	std::vector<Button> m_buttons;
	std::vector<SliderButton> m_sliders;

	Vector<int> m_buttonPos{ 565, 100 };
};