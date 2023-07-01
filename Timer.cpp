#include "Timer.h"
#include "SDL.h"
Timer* Timer::s_Instance = nullptr;

void Timer::Tick()
{
	m_DeltaTime = (SDL_GetTicks() - m_LastTime) * (Target_Fps/1000.f);
	if (m_DeltaTime > Target_Deltatime)
		m_DeltaTime = Target_Deltatime;

	m_LastTime = SDL_GetTicks();
}