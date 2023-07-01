#include "Warrior.h"
#include "TextureManager.h"

Warrior::Warrior(Properties* props) : Character(props)
{ 
	m_Animation = new Animation();
	m_Animation->SetProps(m_TextureId, 1, 5, 100,SDL_FLIP_HORIZONTAL);
}

void Warrior::Draw() 
{
	m_Animation->Draw(m_Transform->X,m_Transform->Y,m_Width,m_Height);
}

void  Warrior::Update(float dt)
{
	m_Animation->Update();
}
void Warrior::Clean()
{
	TextureManager::GetInstance()->Clean();
}