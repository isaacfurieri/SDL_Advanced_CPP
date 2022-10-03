#pragma once
#include <vector>

#include "Button.h"
#include "Game.h"
#include "GameState.h"
#include "Text.h"
#include "MenuState.h"

class ControlsState : public GameState
{
public:

	~ControlsState() override {}

	bool OnEnter() override;
	bool Render() override;
	void OnExit() override;

	GameState* Update() override;

private:

	std::vector<Button> m_buttons;

	Vector<int> m_buttonPos {0, 0};
	Sprite m_spell;
	Text m_movementText, m_spellText;
};