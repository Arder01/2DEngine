#include "Warrior.h"
#include "TextureManager.h"
#include "Input.h"

Warrior::Warrior(Properties* props) : Character(props)
{ 
	m_RigidBody = new RigidBody();
	m_Animation = new Animation();
	m_Animation->SetProps(m_TextureId, 1, 10, 100);
}

void Warrior::Draw() 
{
	m_Animation->Draw(m_Transform->X,m_Transform->Y,m_Width,m_Height);
}

void  Warrior::Update(float dt)
{
	m_Animation->SetProps("Player", 1, 10, 100);
	m_RigidBody->UnSetForce();

	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_D))
	{
		m_Animation->SetProps("Player_Run", 1, 10, 100);
		m_RigidBody->ApplyForceX(2*FORWARD);

	}

	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A))
	{
		m_Animation->SetProps("Player_Run", 1, 10, 100, SDL_FLIP_HORIZONTAL);
		m_RigidBody->ApplyForceX(2*BACKWARD);
	} 
	m_RigidBody->Update(dt);
	
	m_Transform->TranslateX(m_RigidBody->Position().X);
	//m_Transform->TranslateY(m_RigidBody->Position().Y);
	m_Animation->Update();
}
void Warrior::Clean()
{
	TextureManager::GetInstance()->Clean();
}