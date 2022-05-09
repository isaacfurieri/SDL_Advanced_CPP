#include <iostream>
#include "Sprite.h"
#include <SDL_image.h>

Sprite::Sprite()
{
	m_image = nullptr;
	m_animationVelocity = 0.0f;

	m_isAnimated = false;
	m_isAnimationDead = false;
	m_isAnimationLooping = false;

	m_celDimension = { 0, 0 };
	m_imageDimension = { 0, 0 };
	m_spriteDimension = { 0, 0 };
	m_spritePositions = { 0, 0, 0, 0 };
}

bool Sprite::IsAnimationDead()
{
	return m_isAnimationDead;
}

void Sprite::IsAnimated(bool flag)
{
	m_isAnimated = flag;
}

void Sprite::IsAnimationLooping(bool flag)
{
	m_isAnimationLooping = flag;
}

void Sprite::SetImageCel(int column, int row)
{
	m_imageCel = ((row - 1) * m_imageDimension.x) + (column - 1);
}

void Sprite::SetAnimationVelocity(float velocity)
{
	m_animationVelocity = velocity;
}

//This is the resolution of the sprite image as it will appear on-screen
void Sprite::SetSpriteDimension(int width, int height)
{
	m_spriteDimension.x = width;
	m_spriteDimension.y = height;
}

//This is the resolution and col/row dimensions of the sprite image as it is stored in the Assets folder
void Sprite::SetImageDimension(int columns, int rows, int width, int height)
{
	m_imageDimension.x = columns;
	m_imageDimension.y = rows;

	m_celDimension.x = width / columns;
	m_celDimension.y = height / rows;
}

void Sprite::SetFlipImage(Vector<int>& playerPosition, Vector<int>& mousePosition)
{
	if (playerPosition.x - mousePosition.x >= 0)
	{
		m_flipImage = SDL_FLIP_HORIZONTAL;
	}
	else
	{
		m_flipImage = SDL_FLIP_NONE;
	}
}

void Sprite::FlipImage(Vector<int> playerPosition, Vector<int> monsterPosition)
{
	if (playerPosition.x - monsterPosition.x <= 0)
	{
		m_flipImage = SDL_FLIP_HORIZONTAL;
	}
	else
	{
		m_flipImage = SDL_FLIP_NONE;
	}
}

SDL_Point Sprite::GetCentrePosition() const
{
	return { m_spriteDimension.x, m_spriteDimension.y };
}

SDL_Rect Sprite::GetSpritePositions() const
{
	return m_spritePositions;
}

Vector<int> Sprite::GetSpriteDimension() const
{
	return m_spriteDimension;
}

Vector<int> Sprite::GetImageDimension() const
{
	return m_imageDimension;
}

Vector<int> Sprite::GetSpriteDimension()
{
	return m_spriteDimension;
}

bool Sprite::Load(const std::string& filename)
{
	SDL_Surface* rawImageData = IMG_Load(filename.c_str());

	if (!rawImageData)
	{
		std::cout << SDL_GetError() << std::endl;
		std::cout << "Error loading image file." << std::endl;
		return false;
	}

	m_image = SDL_CreateTextureFromSurface(Screen::Instance()->GetRenderer(), rawImageData);

	return true;
}

void Sprite::Unload()
{
	SDL_DestroyTexture(m_image);
}

void Sprite::Update()
{
	if (m_isAnimated)
	{
		static float total = 0.0f;
		total += 0.1f;

		m_imageCel = static_cast<int>(total * m_animationVelocity) % (m_imageDimension.x * m_imageDimension.y);

		if (!m_isAnimationLooping && m_imageCel == (m_imageDimension.x * m_imageDimension.y - 1))
		{
			m_isAnimationDead = true;
		}
	}
}

void Sprite::Render(int xPos, int yPos, double angle)
{
	if (!m_isAnimationDead)
	{
		SDL_Rect sourceRect;
		SDL_Rect targetRect;

		sourceRect.x = (m_imageCel % m_imageDimension.x) * m_celDimension.x;
		sourceRect.y = (m_imageCel / m_imageDimension.x) * m_celDimension.y;
		sourceRect.w = m_celDimension.x;
		sourceRect.h = m_celDimension.y;

		targetRect.x = xPos; 
		targetRect.y = yPos; 
		targetRect.w = m_spriteDimension.x; 
		targetRect.h = m_spriteDimension.y; 

		//Saving Positions
		m_spritePositions.x = xPos;
		m_spritePositions.y = yPos;
		m_spritePositions.w = m_spriteDimension.x;
		m_spritePositions.h = m_spriteDimension.y;

		centre = GetCentrePosition();

		SDL_RenderCopyEx(Screen::Instance()->GetRenderer(), m_image, &sourceRect, &targetRect, angle, &centre, m_flipImage);
	}
}