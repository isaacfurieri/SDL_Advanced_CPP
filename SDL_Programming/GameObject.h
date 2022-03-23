#pragma once

#include <SDL.h>
#include <string>
#include "Input.h"
#include "Screen.h"
#include "Vector2D.h"
#include "Vector.h"

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
	const Vector<int>& GetSize() const;
	const Vector<int>& GetPosition() const;

	void IsAlive(bool flag);
	void IsActive(bool flag);
	void IsVisible(bool flag);

	void SetAngle(float angle);
	void SetTag(const std::string& tag);

	void SetPosition(int x, int y);
	void SetPosition(const Vector<int>& position);

	void SetSize(const Vector<int>& size);
	void SetSize(int width, int height);

	virtual void Update() = 0;
	virtual void Render() = 0;

protected:

	float m_angle;
	std::string m_tag;

	bool m_isAlive;
	bool m_isActive;
	bool m_isVisible;

	Vector<int> m_size;
	Vector<int> m_position;

};