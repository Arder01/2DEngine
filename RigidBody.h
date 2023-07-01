#pragma once
#include "Vector2d.h"
#define UNI_MASS 1.0f
#define GRAVITY 9.8f
#define FORWARD 1
#define BACKWARD -1

#define UPWARD -1
#define DOWNWARD 1
class RigidBody 
{
public:
	RigidBody()
	{
		m_Mass = UNI_MASS;
		m_Gravity = GRAVITY;
	}
	//setting mass and gravity

	inline void SetMass(float mass){ m_Mass = mass; }
	inline void SetGravity(float gravity) { m_Gravity = gravity; }

	//setting force
	inline void ApplyForce(Vector2d F) { m_Force = F; }
	inline void ApplyForceX(float Fx) { m_Force.X = Fx; }
	inline void ApplyForceY(float Fy) { m_Force.Y = Fy; }
	inline void UnSetForce() { m_Force = Vector2d(0, 0); }

	//setting  friction
	inline void ApplyFriction(Vector2d Fr) { m_Friction = Fr; }
	inline void UnSetFriction() { m_Friction = Vector2d(0, 0); }

	//Getters
	inline float GetMass() { return m_Mass; }
	inline  Vector2d Position() { return m_Position; }
	inline  Vector2d Veloctiy() { return m_Velocity; }
	inline  Vector2d Acceleration() { return m_Acceleration; }

	//Update
	void Update(float dt)
	{
		m_Acceleration.X = (m_Force.X + m_Friction.X) / m_Mass;
		m_Acceleration.Y = m_Gravity+m_Force.Y/ m_Mass;
		m_Velocity = m_Acceleration * dt;
		m_Position = m_Velocity * dt;
	}
private:
	float m_Mass, m_Gravity;
	Vector2d m_Force, m_Friction;

	Vector2d m_Acceleration;
	Vector2d m_Velocity;
	Vector2d m_Position;


};