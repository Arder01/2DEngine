 #pragma once
#include "IObject.h"
#include "Transform.h"
#include "SDL.h"
#include <string>
#include <iostream>

struct Properties
{
public:
	Properties(std::string textureId, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE)
	{
		X = x;
		Y = y;
		Flip = flip;
		Width = width;
		Height = height;
		TextureId = textureId;
	}
public:
	std::string TextureId;
	int Width, Height;
	float X, Y;
	SDL_RendererFlip Flip;
};

class GameObject : public IObject
{
public:
	GameObject(Properties* props): m_TextureId(props->TextureId), m_Width(props->Width), m_Height(props->Height), m_Flip(props->Flip){
		m_Transform = new Transform(props->X, props->Y);
	}
	virtual void Draw() = 0;
	virtual void Update(float dt) = 0;
	virtual void Clean() = 0;

protected:
	Transform* m_Transform;
	int m_Width, m_Height;
	std::string m_TextureId;
	SDL_RendererFlip m_Flip;
};