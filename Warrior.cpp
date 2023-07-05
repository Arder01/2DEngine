#include "Warrior.h"
#include "TextureManager.h"
#include "Input.h"
#include "Camera.h"
#include "CollisionHandler.h"
#include "Engine.h"
#include "Animation.h"


Warrior::Warrior(Properties* props) : Character(props)
{ 
	m_JumpTime = JUMP_TIME;
	m_JumpForce = JUMP_FORCE;

	m_Collider = new Collider();
	m_Collider->SetBuffer(-50, -45, 30, 0);


	m_RigidBody = new RigidBody();
	m_Animation = new Animation();
	m_Animation->SetProps(m_TextureId, 1, 10, 100);

}

void Warrior::Draw() 
{
	m_Animation->Draw(m_Transform->X,m_Transform->Y,m_Width,m_Height);
	std::cout << "TransForm Y: " << m_Transform->Y << std::endl;
	
	Vector2d cam = Camera::GetInstance()->GetPosition();
	SDL_Rect box = m_Collider->Get();
	box.x -= cam.X;
	box.y -= cam.Y;
	SDL_RenderDrawRect(Engine::GetInstance()->GetRenderer(), &box);
}

void  Warrior::Update(float dt)
{
	m_Animation->SetProps("Player", 1, 10, 100);
	m_RigidBody->UnSetForce();

	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_D))
	{
		m_RigidBody->ApplyForceX(6*FORWARD);
		m_Animation->SetProps("Player_Run", 1, 10, 100);

	}

	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A))
	{
		m_RigidBody->ApplyForceX(6*BACKWARD);
		m_Animation->SetProps("Player_Run", 1, 10, 100, SDL_FLIP_HORIZONTAL);
	} 

	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_SPACE) && m_IsGrounded)
	{
		m_IsJumping = true;
		m_IsGrounded = false;
		m_RigidBody->ApplyForceY(UPWARD * m_JumpForce);
	}

	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_SPACE) && m_IsJumping && m_JumpTime > 0)
	{
		m_JumpTime -= dt;
		m_RigidBody->ApplyForceY(UPWARD * m_JumpForce);
	}
	else
	{
		m_IsJumping = false;
		m_JumpTime = JUMP_TIME;
	}

	

	m_RigidBody->Update(dt);

	m_LastSafePosition.X = m_Transform->X;
	//std::cout << "Last safe Position X: " << m_LastSafePosition.X << std::endl;
	m_Transform->X += m_RigidBody->Position().X;
	m_Collider->set(m_Transform->X, m_Transform->Y,80,80 );

	if (CollisionHandler::GetInstance()->MapCollision(m_Collider->Get()))
	{
		m_Transform->X = m_LastSafePosition.X;
	}


	m_RigidBody->Update(dt);
	m_LastSafePosition.Y = m_Transform->Y;
	//std::cout << "Last safe Position Y: before Collision " << m_LastSafePosition.Y << std::endl;
	m_Transform->Y += m_RigidBody->Position().Y;
	m_Collider->set(m_Transform->X, m_Transform->Y,80,80 );

	if (CollisionHandler::GetInstance()->MapCollision(m_Collider->Get()))
	{
		m_IsGrounded = true;
		m_Transform->Y = m_LastSafePosition.Y;
		m_RigidBody->ApplyForceY(UPWARD * GRAVITY);

		//std::cout << "Last safe Position Y: " << m_LastSafePosition.Y << std::endl;
	}
	else {
		m_IsGrounded = false;
	}
	m_RigidBody->Update(dt);
	
	m_Transform->TranslateX(m_RigidBody->Position().X);
	m_Transform->TranslateY(m_RigidBody->Position().Y);

	m_Origin->X = m_Transform->X + m_Width / 2;
	m_Origin->Y = m_Transform->Y + m_Height / 2;
	m_Animation->Update();
}
void Warrior::Clean()
{
	TextureManager::GetInstance()->Drop(m_TextureId);
}