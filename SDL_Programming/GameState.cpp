#include "GameState.h"

bool GameState::OnEnter() 
{
	//Load Screen Asset
	//===========================================


	//Init music Asset
	//===========================================
	Music::Initialize();

	Music music;

	music.Load("Assets/Music/background_music.mp3");
	music.Play(Music::PlayLoop::PLAY_ENDLESS);
	//music.Load("Assets/Music/background_music.mp3");

	//===========================================
	//Init music system
	//===========================================


	return 1;
}