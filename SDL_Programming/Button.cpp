#include "Button.h"
#include "Game.h"

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
	sfxClicked.Load("Assets/Music/fireball_cast.wav");
	//sfxClicked.Load("Assets/Sounds/buttonClicked.wav");
	sfxHover.Load("Assets/Sounds/buttonHover.wav");
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
	m_spritePosition.w = m_buttonSprite.GetSpriteDimension().x;
	m_spritePosition.h = m_buttonSprite.GetSpriteDimension().y;
	
	m_mousePosition.x = Input::Instance()->GetMousePosition().x;
	m_mousePosition.y = Input::Instance()->GetMousePosition().y;
	m_mousePosition.w = 1;
	m_mousePosition.h = 1;

	m_buttonState = ButtonState::Default;

	if (SDL_HasIntersection(&m_mousePosition, &m_spritePosition))
	{
		if (Input::Instance()->IsMouseClicked())
		{
			sfxClicked.Play(1);
			m_buttonState = ButtonState::Clicked;
		}
		m_buttonSprite.SetImageCel(2, 1);
		sfxHover.Play(1);
		m_buttonState = ButtonState::Hover;
	}
}

void Button::Render()
{
	m_buttonSprite.Render(this->GetPosition().x, this->GetPosition().y, 0.0);
}
