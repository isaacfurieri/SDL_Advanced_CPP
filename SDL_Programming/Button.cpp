#include "Button.h"

Button::Button(const std::string& filename)
{
	m_mousePosition = { 0, 0, 0, 0 };
	m_spritePosition = { 0, 0, 0, 0 };
	SetTag(filename);
	m_buttonState = ButtonState::Default;
	//Sprites
	m_buttonSprite.Load("Assets/Buttons/" + GetTag() + "Button.png");
	m_buttonSprite.SetImageDimension(2, 1, 1200, 200);
	m_buttonSprite.SetSpriteDimension(150, 75);

	//Sounds
	m_sfxClicked.Load("Assets/Sounds/buttonClicked.wav");
	m_sfxHover.Load("Assets/Sounds/buttonHover.wav");
}

const Button::ButtonState& Button::GetState() const
{
	return m_buttonState;
}

void Button::Update()
{
	m_buttonSprite.SetImageCel(1, 1);
	m_spritePosition.x = this->GetPosition().x;
	m_spritePosition.y = this->GetPosition().y;
	
	//m_spritePosition.x = Screen::Instance()->GetResolution().x - m_buttonSprite.GetSpriteDimension().x / 2;
	//m_spritePosition.y = this->GetPosition().y;
	
	m_spritePosition.w = m_buttonSprite.GetSpriteDimension().x;
	m_spritePosition.h = m_buttonSprite.GetSpriteDimension().y;
	
	m_mousePosition.x = Input::Instance()->GetMousePosition().x;
	m_mousePosition.y = Input::Instance()->GetMousePosition().y;
	m_mousePosition.w = 1;
	m_mousePosition.h = 1;

	m_buttonState = ButtonState::Default;
	//std::cout << isHover << std::endl;

	if (!SDL_HasIntersection(&m_mousePosition, &m_spritePosition))
	{
		//std::cout << isHover << std::endl;
		isHover = false;
	}
	if (SDL_HasIntersection(&m_mousePosition, &m_spritePosition))
	{
		m_buttonSprite.SetImageCel(2, 1);
		m_buttonState = ButtonState::Hover;
		if (Input::Instance()->IsMouseClicked())
		{
			m_sfxClicked.Play(0);
			m_buttonState = ButtonState::Clicked;
		}
		if (!isHover)
		{
			m_sfxHover.Play(0);
			isHover = true;
			//std::cout << isHover << std::endl;
		}
	}

	//this->SetPosition((Screen::Instance()->GetResolution().x / 2) - m_buttonSprite.GetSpriteDimension().x / 2, this->GetPosition().y);
}

void Button::Render()
{
	m_buttonSprite.Render(this->GetPosition().x, this->GetPosition().y, 0.0);
}
