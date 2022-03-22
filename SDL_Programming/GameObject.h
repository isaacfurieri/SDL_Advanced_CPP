#pragma once

#include <SDL.h>
#include <string>
#include "Input.h"
#include "Screen.h"
#include "Vector2D.h"

//Abstract base class - any class with at least 1 pure virtual function

class GameObject
{

public:

	GameObject();

	bool IsAlive() const;
	bool IsActive() const;
	bool IsVisible() const;

	float GetAngle() const;
	const std::string& GetTag() const;
	const Vector2D& GetSize() const;
	const Vector2D& GetPosition() const;

	void IsAlive(bool flag);
	void IsActive(bool flag);
	void IsVisible(bool flag);

	void SetAngle(float angle);
	void SetTag(const std::string& tag);

	void SetPosition(int x, int y);
	void SetPosition(const Vector2D& position);

	void SetSize(const Vector2D& size);
	void SetSize(int width, int height);

	virtual void Update(Input& input) = 0;
	virtual void Render(Screen* screen) = 0;

protected:

	float m_angle;
	std::string m_tag;

	bool m_isAlive;
	bool m_isActive;
	bool m_isVisible;

	Vector2D m_size;
	Vector2D m_position;

};