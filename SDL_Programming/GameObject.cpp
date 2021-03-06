#include "GameObject.h"

GameObject::GameObject()
{
    m_angle = 0.0f;
    m_isAlive = true;
    m_isActive = true;
    m_isVisible = true;
}

float GameObject::GetAngle() const
{
    return m_angle;
}

const std::string& GameObject::GetTag() const
{
    return m_tag;
}

const Vector<int>& GameObject::GetSize() const
{
    return m_size;
}

const Vector<int>& GameObject::GetPosition() const
{
    return m_position;
}

void GameObject::IsAlive(bool flag)
{
    m_isAlive = flag;
}

void GameObject::IsActive(bool flag)
{
    m_isActive = flag;
}

void GameObject::IsVisible(bool flag)
{
    m_isVisible = flag;
}

bool GameObject::IsAlive() const
{
    return m_isAlive;
}

bool GameObject::IsActive() const
{
    return m_isActive;
}

bool GameObject::IsVisible() const
{
    return m_isVisible;
}

void GameObject::SetTag(const std::string& tag)
{
    m_tag = tag;
}

void GameObject::SetAngle(float angle)
{
    m_angle = angle;
}

void GameObject::SetPosition(int x, int y)
{
    m_position = { x, y };
}

void GameObject::SetPosition(const Vector<int>& position)
{
    m_position = position;
}

void GameObject::SetSize(const Vector<int>& size)
{
    m_size = size;
}

void GameObject::SetSize(int width, int height)
{
    m_size = { width, height };
}