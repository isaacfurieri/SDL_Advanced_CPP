#include "Score.h"
#include <iostream>

Score::Score()
{
	m_score = 0;
	m_text.Load("Assets/Fonts/game_over.ttf", 200);
	m_text.SetColor(255, 0, 0, 255);
	m_text.SetDimension(150, 100);
}

Score::~Score()
{
	m_text.Unload();
}

void Score::SetScore(int score)
{
	m_score = m_score + score;
	m_text.SetText("Score: " + std::to_string(m_score));
}

int Score::GetScore()
{
	return m_score;
}

void Score::Render()
{
	m_text.Render(m_position.x, m_position.y);
}