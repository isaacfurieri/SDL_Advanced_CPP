#pragma once
#include <Windows.h>
#include <string>
#include <SDL.h>
#include "Vector.h"

class Screen
{

public:

	static Screen* Instance();
	SDL_Renderer* GetRenderer();
	SDL_Window* GetWindow();
	Vector<int> GetResolution();
	
	bool Initialize(const std::string& windowTitle = "<No name>",
		int width = 1280,
		int height = 720);

	void Clear();
	void Present();
	void Shutdown();

private:

	Screen() {}
	Screen(const Screen&);
	Screen& operator=(const Screen&);

	//int m_width{ 0 };
	//int m_height{ 0 };

	SDL_Window* m_window{ nullptr };
	SDL_Renderer* m_renderer{ nullptr };
	Vector<int> m_size;
};