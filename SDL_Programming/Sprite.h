#pragma once

#include <string>
#include <SDL.h>
#include "Screen.h"
#include "Vector2D.h"

class Sprite
{

public:

	Sprite();
	~Sprite() {}

	void IsAnimated(bool flag);
	void IsAnimationLooping(bool flag);

	void SetImageCel(int column, int row);
	void SetAnimationVelocity(float velocity);
	void SetSpriteDimension(int width, int height); //on-screen
	void SetImageDimension(int columns, int rows, int width, int height); //in-folder

	Vector2D GetSpriteDimension() const;
	Vector2D GetImageDimension() const;
	Vector2D GetSpriteDimension();

	bool Load(const std::string& filename, Screen& screen);
	void Unload();

	void Update();
	void Render(int xPos, int yPos, double angle, Screen& screen);

private:

	int m_imageCel;
	float m_animationVelocity;

	bool m_isAnimated;
	bool m_isAnimationDead;
	bool m_isAnimationLooping;

	SDL_Texture* m_image;
	Vector2D m_celDimension;
	Vector2D m_imageDimension;
	Vector2D m_spriteDimension;
};