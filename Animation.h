#pragma once
#include "SDL.h"
#include <string>
class Animation
{
public:
	Animation() {}
	void Update();
	void Draw(float x,float y,int SpriteWidth, int SpriteHeight);
	void SetProps(std::string TextureId, int SpriteRow, int FrameCount, int AnimSpeed, SDL_RendererFlip flip = SDL_FLIP_NONE); 

private:
	int m_SpriteRow, m_SpriteFrame;
	int m_AnimSpeed,m_FrameCount;
	std::string m_TextureId;
	SDL_RendererFlip m_Flip;
};

