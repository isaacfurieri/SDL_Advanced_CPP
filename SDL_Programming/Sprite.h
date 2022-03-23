#pragma once

#include <string>
#include <SDL.h>
#include "Screen.h"
#include "Vector2D.h"
#include "Vector.h"

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

	Vector<int> GetSpriteDimension() const;
	Vector<int> GetImageDimension() const;
	Vector<int> GetSpriteDimension();

	bool Load(const std::string& filename);
	void Unload();

	void Update();
	void Render(int xPos, int yPos, double angle);

private:

	int m_imageCel{ 0 };
	float m_animationVelocity;

	bool m_isAnimated;
	bool m_isAnimationDead;
	bool m_isAnimationLooping;

	SDL_Texture* m_image;
	Vector<int> m_celDimension;
	Vector<int> m_imageDimension;
	Vector<int> m_spriteDimension;
};