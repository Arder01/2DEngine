#include "Animation.h"
#include "TextureManager.h"

void Animation::Update()
{
	m_SpriteFrame = (SDL_GetTicks() / m_AnimSpeed) % m_FrameCount;
}

void Animation::Draw(float x, float y, int SpriteWidth, int SpriteHeight)
{
	TextureManager::GetInstance()->DrawFrame(m_TextureId, x, y, SpriteWidth, SpriteHeight, m_SpriteRow, m_SpriteFrame, m_Flip);
}

void Animation::SetProps(std::string TextureId, int SpriteRow, int FrameCount, int AnimSpeed, SDL_RendererFlip flip)
{
	m_TextureId = TextureId;
	m_SpriteRow = SpriteRow;
	m_FrameCount = FrameCount;
	m_AnimSpeed = AnimSpeed;
	m_Flip = flip;
}