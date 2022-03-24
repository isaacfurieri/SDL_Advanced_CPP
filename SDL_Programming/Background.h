#pragma once
#include "Game.h"
#include "GameObject.h"
#include "Sprite.h"

class Background : public GameObject
{

public:

	Background();
	~Background();

	virtual void Update();
	virtual void Render();

private:

	Sprite m_image;
};
//You could make screen a UP (UNIQUE POINTER)
//then to pass the pointer around use screenPtr.get()
//Receive the pointer using Screen* scrPtr