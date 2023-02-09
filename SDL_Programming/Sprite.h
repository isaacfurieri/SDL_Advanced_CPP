#pragma once

#include <map>
#include <string>
#include <SDL.h>
#include "Screen.h"
#include "Vector.h"

class Sprite
{

public:

	Sprite();
	~Sprite() {}

	bool IsAnimationDead();
	
	void IsAnimated(bool flag);
	void IsAnimationLooping(bool flag);

	void IsAnimationDead(bool flag);
	void SetImageCel(int column, int row);
	void SetAnimationVelocity(float velocity);
	void SetSpriteDimension(int width, int height); //on-screen
	void SetImageDimension(int columns, int rows, int width, int height); //in-folder
	void SetFlipImage(Vector<int>& playerPosition, Vector<int>& mousePosition); //decide to flip or NOT
	void FlipImage(Vector<int> playerPosition, Vector<int> monsterPosition); //decide to flip or NOT

	Vector<int> GetCentrePosition() const;
	SDL_Rect GetSpritePositions() const;

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

	SDL_Point centre {0 , 0};
	SDL_Rect m_spritePositions;
	SDL_RendererFlip m_flipImage { SDL_FLIP_NONE };
	SDL_Texture* m_image;
	Vector<int> m_celDimension;
	Vector<int> m_imageDimension;
	Vector<int> m_spriteDimension;

	//TODO -- MAP OF TEXTURES -- https://github.com/karsten-vermeulen-dev/Handmade/blob/master/Handmade/Texture.cpp
	//Find a better way to load/unload textures. (Load once, use when needs).
	
	//static std::string s_rootFolder;
	//static std::map<std::string, SDL_Texture*> s_images;

};