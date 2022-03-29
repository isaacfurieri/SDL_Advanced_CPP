#include "Button.h"

Button::Button(const std::string& filename)
{
	SetTag(filename);

	//Sprites
	m_buttonSprite.Load("Assets/Menu/" + GetTag() + ".png");
	m_buttonSprite.SetImageDimension(2, 13, 1200, 2600);
	m_buttonSprite.SetSpriteDimension(150, 75);

	//Music
	//m_isClickedMusic.Load("Assets/Music/GUI_Sounds/GUI_Button_Clicked_Sound_Effects.wav");
	//m_isOverMusic.Load("Assets/Music/GUI_Sounds/GUI_Button_Over_Sound_Effects3.wav");

	m_spritePosition.x = m_buttonSprite.GetSpritePositions().x;
	m_spritePosition.y = m_buttonSprite.GetSpritePositions().y;
	m_spritePosition.w = m_buttonSprite.GetSpritePositions().w;
	m_spritePosition.h = m_buttonSprite.GetSpritePositions().h;

	m_mousePosition.w = 1;
	m_mousePosition.h = 1;

}

const Button::ButtonState& Button::GetState() const
{
	return m_buttonState;
}

void Button::Update()
{
	m_mousePosition.x = Input::Instance()->GetMousePosition().x;
	m_mousePosition.y = Input::Instance()->GetMousePosition().y;

	m_buttonState = ButtonState::Default;

	//for earch button
	//{
	if (SDL_HasIntersection(&m_mousePosition, &m_spritePosition))
	{
		if (m_isOver && Input::Instance()->IsMouseClicked())
		{
			m_buttonState = ButtonState::Clicked;
		}
		m_isOver = true;
		m_buttonState = ButtonState::Hover;
		//set isOver image cel
		//m_buttonSprite.SetImageCel(1, 4);
	}
	else
	{
		m_isOver = false;
		//set normal image cel
	}




	//}
}

void Button::Render()
{
		//m_buttonSprites.SetImageCel((int)m_buttonState, row);
}
