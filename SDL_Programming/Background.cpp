#include "Background.h"

Background::Background()
{
	m_image.Load("Assets/Images/Background/Room.png", Screen::Instance());
	m_image.SetImageDimension(1, 1, 1280, 720);
	m_image.SetSpriteDimension(1280, 720);
}

Background::~Background()
{
	m_image.Unload();
}

void Background::Update(Input& input)
{
	//create background manipulation
}

void Background::Render(Screen* screen)
{
	m_image.Render(m_position.x, m_position.y, m_angle, Screen::Instance());
}
