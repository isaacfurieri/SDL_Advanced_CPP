#pragma once

#include "GameObject.h"
#include "Text.h"

class Score : public GameObject
{

public:

	Score();
	~Score();

	void SetScore(int score);
	int GetScore();

	virtual void Update() {}
	virtual void Render();

private:

	int m_score;
	Text m_text;

};