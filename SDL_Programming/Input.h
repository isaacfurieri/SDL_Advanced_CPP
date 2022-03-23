#pragma once

#include <SDL.h>
#include "Vector2D.h"

class Input
{

public:

	static Input* Instance();

	Vector2D MousePos;
	void Update();

	char GetKeyUp() const;
	char GetKeyDown() const;

	int GetMouseButtonUp() const;
	int GetMouseButtonDown() const;

	bool IsKeyPressed() const;
	bool IsMouseClicked() const;
	bool IsWindowClosed() const;

	Vector2D GetMousePosition() const;

private:

	Input() {}
	Input(const Input&);
	Input& operator=(const Input&);

	char m_keyUp{ ' ' };
	char m_keyDown{ ' ' };

	bool m_isKeyPressed{ false };
	bool m_isMouseClicked{ false };
	bool m_isWindowClosed{ false };

	int m_mouseButtonUp{ 0 };
	int m_mouseButtonDown{ 0 };

	Vector2D m_mousePosition{ 0 , 0 };

};