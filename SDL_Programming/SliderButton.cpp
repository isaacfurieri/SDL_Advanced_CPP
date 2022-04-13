#include "SliderButton.h"

int SliderButton::GetSliderValue()
{
	return GetPinPosition().x - m_sliderPosition.x;
}

SliderButton::SliderButton(const std::string& slidername)
{
	//TODO FIX TAG AND BE ABLE TO CREATE MORE THEN ONCE SLIDER
	SetTag(slidername);
	m_mousePosition = { 0, 0, 0, 0 };
	m_sliderState = SliderState::Default;
	
	//Sprites
	m_sliderBar.Load("Assets/Buttons/SliderBarButton.png");
	m_sliderBar.SetImageDimension(1, 1, 206, 17);
	m_sliderBar.SetSpriteDimension(207, 17);
	
	m_sliderPin.Load("Assets/Buttons/SliderPinButton.png");
	m_sliderPin.SetImageDimension(1, 1, 22, 40);
	m_sliderPin.SetSpriteDimension(22, 40);
	
	m_pinPosition = { 0, 0, m_sliderPin.GetSpriteDimension().x, m_sliderPin.GetSpriteDimension().y };
	m_sliderPosition = { 0, 0, m_sliderBar.GetSpriteDimension().x, m_sliderPin.GetSpriteDimension().y };
}

const SliderButton::SliderState& SliderButton::GetState() const
{
	return m_sliderState;
}

SDL_Rect SliderButton::GetPinPosition()
{
	return m_pinPosition;
}

void SliderButton::SetSliderPinPosition()
{
	if(Input::Instance()->GetMousePosition().x > m_sliderPosition.x && Input::Instance()->GetMousePosition().x < m_sliderPosition.x + m_sliderPosition.w)
	{
		if (this->GetPinPosition().x >= m_sliderPosition.x && this->GetPinPosition().x <= m_sliderPosition.x + m_sliderPosition.w)
		{
			m_pinPosition.x = Input::Instance()->GetMousePosition().x;
		}
	}
}

void SliderButton::Update()
{
	if (!m_sprite && m_sliderPosition.x > 0 && m_sliderPosition.y > 0)
	{
		m_pinPosition.x = m_sliderPosition.x;
		m_pinPosition.y = m_sliderPosition.y;
		m_sprite = true;
	}

	m_sliderPosition.x = this->GetPosition().x;
	m_sliderPosition.y = this->GetPosition().y;

	m_mousePosition.x = Input::Instance()->GetMousePosition().x;
	m_mousePosition.y = Input::Instance()->GetMousePosition().y;
	m_mousePosition.w = 1;
	m_mousePosition.h = 1;

	m_sliderState = SliderState::Default;

	if (!SDL_HasIntersection(&m_mousePosition, &m_sliderPosition))
	{
		isHover = false;
	}
	if (SDL_HasIntersection(&m_mousePosition, &m_sliderPosition))
	{
		m_sliderState = SliderState::Hover;
		if (Input::Instance()->IsMouseClicked())
		{
			std::cout << GetPinPosition().x - m_sliderPosition.x << std::endl;
			m_sliderState = SliderState::Clicked;
		}
		if (!isHover)
		{
			isHover = true;
		}
	}
}

void SliderButton::Render()
{
	m_sliderBar.Render(m_sliderPosition.x, m_sliderPosition.y + 12, 0.0);
	m_sliderPin.Render(GetPinPosition().x - m_sliderPin.GetSpriteDimension().x / 3, m_sliderPosition.y, 0.0);
}
