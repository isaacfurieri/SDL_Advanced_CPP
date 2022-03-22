#pragma once
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
	Sprite m_image;
};