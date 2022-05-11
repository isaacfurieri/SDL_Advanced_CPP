#pragma once
#include <vector>

#include "Background.h"
#include "Button.h"
#include "GameState.h"
#include "MenuState.h"
#include "PlayState.h"

class EndState : public GameState
{
public:

	enum State
	{
		Lose,
		Win
	};

	EndState(EndState::State endState);
	~EndState() override {}

	bool Render() override;
	bool OnEnter() override;
	void OnExit() override;

	GameState* Update() override;

private:

	State m_endState;
	Background m_background;
	std::vector<Button> m_buttons;
};

