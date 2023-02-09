#pragma once
#include "Game.h"
#include "GameObject.h"
#include "Music.h"
#include "Sprite.h"

//TODO Add music to background class, instead of using it on MainGame.
//Rebuild Background class
//https://github.com/karsten-vermeulen-dev/Handmade/blob/master/Handmade/Background.h

class Background : public GameObject
{

public:

	Background() {}
	~Background();

	void Load(const std::string& imageName, const std::string& musicName);

	virtual void Update();
	virtual void Render();

private:

	Sprite m_image;
	Music m_music;
};