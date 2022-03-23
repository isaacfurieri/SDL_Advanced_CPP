#include "Input.h"

Input* Input::Instance()
{
	static Input* inputObject = new Input();
	return inputObject;
}

char Input::GetKeyUp() const
{
	return m_keyUp;
}

char Input::GetKeyDown() const
{
	return m_keyDown;
}

int Input::GetMouseButtonUp() const
{
	return m_mouseButtonUp;
}

int Input::GetMouseButtonDown() const
{
	return m_mouseButtonDown;
}

bool Input::IsKeyPressed() const
{
	return m_isKeyPressed;
}

bool Input::IsMouseClicked() const
{
	return m_isMouseClicked;
}

bool Input::IsWindowClosed() const
{
	return m_isWindowClosed;
}

Vector2D Input::GetMousePosition() const
{
	return m_mousePosition;
}

void Input::Update()
{

	SDL_Event events;

	while (SDL_PollEvent(&events))
	{

		if (events.type == SDL_QUIT)
		{
			m_isWindowClosed = true;
		}

		else if (events.type == SDL_KEYDOWN)
		{
			m_isKeyPressed = true;
			m_keyDown = events.key.keysym.sym;
		}

		else if (events.type == SDL_KEYUP)
		{
			m_isKeyPressed = false;
			m_keyDown = ' ';
			m_keyUp = events.key.keysym.sym;
		}

		else if (events.type == SDL_MOUSEBUTTONDOWN)
		{
			m_isMouseClicked = true;
			m_mouseButtonDown = events.button.button;
		}

		else if (events.type == SDL_MOUSEBUTTONUP)
		{
			m_isMouseClicked = false;
			m_mouseButtonUp = events.button.button;
		}

		else if (events.type == SDL_MOUSEMOTION)
		{
			m_mousePosition.x = events.motion.x;
			m_mousePosition.y = events.motion.y;
		}


	}

}
