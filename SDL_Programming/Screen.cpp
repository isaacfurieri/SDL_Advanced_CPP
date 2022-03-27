#include <iostream>
#include <SDL_syswm.h>
#include "Screen.h"

Screen* Screen::Instance()
{
	static Screen* screenObject = new Screen();
	return screenObject;
}

bool Screen::Initialize(const std::string& windowTitle, int width, int height)
{
	m_size.x = width;
	m_size.y = height;

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "Error initializing SDL." << std::endl;
		return false;
	}

	m_window = SDL_CreateWindow(windowTitle.c_str(),       //game window title
							    SDL_WINDOWPOS_CENTERED,    //pos x
							    SDL_WINDOWPOS_CENTERED,    //pos y
							    width,                     //width
							    height,                    //height
							    0);                        //flags

	if (!m_window)
	{
		std::cout << "Error creating game window." << std::endl;
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!m_renderer)
	{
		std::cout << "Error creating renderer." << std::endl;
		return false;
	}

    return true;
}

Vector<int> Screen::GetResolution()
{
	return m_size;
}

void Screen::Clear()
{
	SDL_RenderClear(m_renderer);
}

void Screen::Present()
{
	SDL_RenderPresent(m_renderer);
}

void Screen::Shutdown()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

SDL_Renderer* Screen::GetRenderer()
{
	return m_renderer;
}

SDL_Window* Screen::GetWindow()
{
	return m_window;
}
