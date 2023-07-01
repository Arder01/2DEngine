#include "Input.h"
#include "Engine.h"

Input* Input::s_Instance = nullptr;

Input::Input()
{
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}
void Input::Listen()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT: Engine::GetInstance()->Quit(); break;
		case SDL_KEYDOWN:KeyDown(); break;
		case SDL_KEYUP: KeyUp(); break;
		}
	}
}

bool Input::GetKeyDown(SDL_Scancode Key) {
	if (m_KeyStates[Key] == 1)
		return true;
	else
		return false;

}

void Input::KeyUp() {
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}

void Input::KeyDown() {
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}