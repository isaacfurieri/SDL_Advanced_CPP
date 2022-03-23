#include "MenuButtons.h"

MenuButtons::MenuButtons()
{
	//Mouse Out Buttons
	//Play Button
	m_image[Play].Load("Assets/Menu/LargeButtons/LargeButtons/PlayButton.png", Screen::Instance());
	//Resume Button
	m_image[Resume].Load("Assets/Menu/LargeButtons/LargeButtons/ResumeButton.png", Screen::Instance());
	//Settings Button
	m_image[Settings].Load("Assets/Menu/LargeButtons/LargeButtons/SettingsButton.png", Screen::Instance());
	//Exit Button
	m_image[Exit].Load("Assets/Menu/LargeButtons/LargeButtons/ExitButton.png", Screen::Instance());
	//Back Button
	m_image[Back].Load("Assets/Menu/LargeButtons/LargeButtons/BackButton.png", Screen::Instance());

	//Mouse Over Colored Buttons
	//Play Button
	m_image[Play].Load("Assets/Menu/LargeButtons/ColoredLargeButtons/Playcol_Button.png", Screen::Instance());
	//Resume Button
	m_image[Resume].Load("Assets/Menu/LargeButtons/ColoredLargeButtons/Resumecol_Button.png", Screen::Instance());
	//Settings Button
	m_image[Settings].Load("Assets/Menu/LargeButtons/ColoredLargeButtons/Settingscol_Button.png", Screen::Instance());
	//Exit Button
	m_image[Exit].Load("Assets/Menu/LargeButtons/ColoredLargeButtons/Exitcol_Button.png", Screen::Instance());
	//Back Button
	m_image[Back].Load("Assets/Menu/LargeButtons/ColoredLargeButtons/Backcol_Button.png", Screen::Instance());

	m_image[Play].SetSpriteDimension(150, 75);
	m_image[Resume].SetSpriteDimension(150, 75);
	m_image[Settings].SetSpriteDimension(150, 75);
	m_image[Exit].SetSpriteDimension(150, 75);
	m_image[Back].SetSpriteDimension(150, 75);

	m_image[Play].SetImageDimension(1, 1, 600, 200);
	m_image[Resume].SetImageDimension(1, 1, 600, 200);
	m_image[Settings].SetImageDimension(1, 1, 600, 200);
	m_image[Exit].SetImageDimension(1, 1, 600, 200);
	m_image[Back].SetImageDimension(1, 1, 600, 200);

}

void MenuButtons::Update(Input* input)
{
}

void MenuButtons::Render(Screen& screen)
{
	for (auto i = 0; i < TotalButtons; i++)
	{
		m_image[i].Render(Screen::Instance()->GetResolution().x + m_image[i].GetSpriteDimension().x, 200 + m_image[i].GetSpriteDimension().y, 0.0f, Screen::Instance() );
	}
}