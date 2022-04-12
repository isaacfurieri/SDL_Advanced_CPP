#pragma once
#include <vector>

#include "SliderButton.h"
#include "Game.h"
#include "GameState.h"
#include "Sprite.h"

class OptionsState : public GameState
{
public:
	~OptionsState() override {}

	bool OnEnter() override;
	GameState* Update() override;
	bool Render() override;
	void OnExit() override;

private:

	Vector<int> buttonPos{ 565, 100 };
	std::vector<SliderButton> sliders;
};