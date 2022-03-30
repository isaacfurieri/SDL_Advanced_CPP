#pragma once
#include <iostream>
#include <vector>

#include "Button.h"
#include "GameState.h"
#include "Sound.h"
#include "Sprite.h"
#include "Screen.h"

class MenuState : public GameState
{

public:

	~MenuState() override {}

	bool OnEnter() override;
	GameState* Update() override;
	bool Render() override;
	void OnExit() override;

private:

	//All menu stuff declared here!
	bool isOver{ false };

	std::vector<Button> buttons;

	//Sound m_isClickedMusic, m_isOverMusic;
	Vector<int> buttonPos{ 565, 100 };
};