#include "GameState.h"

bool GameState::OnEnter()
{
	return 1;
}

GameState* GameState::Update()
{
	return this;
}

bool GameState::Render()
{
	return true;
}

void GameState::OnExit()
{
}
