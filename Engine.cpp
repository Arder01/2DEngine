#include "Engine.h"
#include <iostream>

Engine* Engine::s_Instance = nullptr;

bool Engine::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG)!=0)
	{
		SDL_Log("Failed to initialize SDL :  %s", SDL_GetError());
		return false;
	}

	m_Window = SDL_CreateWindow("2D Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (m_Window == nullptr)
	{
		SDL_Log("Failed to initialize SDL :  %s", SDL_GetError());
		return false;
	}

	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_Renderer == nullptr) {
		SDL_Log("Failed to initialize SDL :  %s", SDL_GetError());
		return false;
	}


	return m_IsRunning = true;
}

void Engine::Update()
{
	SDL_Log("asdfasdf");
}

void Engine::Events()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		Quit();
		break;

	}
}

void Engine::Render()
{
	SDL_SetRenderDrawColor(m_Renderer, 123, 215, 206,150);
	SDL_RenderPresent(m_Renderer);
}

bool Engine::Clean() {
	return true;
}

void Engine::Quit()
{
	m_IsRunning = false;
}