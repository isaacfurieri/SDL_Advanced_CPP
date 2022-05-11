#include "Background.h"

Background::~Background()
{
	m_image.Unload();
	m_music.Unload();
}

void Background::Load(const std::string& imageName, const std::string& musicName)
{
	//Load Image Settings
	auto screenSize = Screen::Instance()->GetResolution();
	
	m_image.Load("Assets/Images/Background/" + imageName + ".png");
	m_image.SetImageDimension(1, 1, screenSize.x, screenSize.y);
	m_image.SetSpriteDimension(screenSize.x, screenSize.y);

	m_music.Load("Assets/Music/" + musicName + ".mp3");
	m_music.Play(Music::PlayLoop::PLAY_ENDLESS);
	m_music.SetVolume(50);
}

void Background::Update()
{
	//create background manipulation
	m_image.SetSpriteDimension(Screen::Instance()->GetResolution().x, Screen::Instance()->GetResolution().y);
	m_image.Update();
}

void Background::Render()
{
	m_image.Render(m_position.x, m_position.y, m_angle);
}
