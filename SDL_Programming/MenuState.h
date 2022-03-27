#pragma once
#include <iostream>

#include "GameState.h"
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
	Sprite m_image;
	Sprite m_exitButton;
	Sprite m_exitButtonRed;
};