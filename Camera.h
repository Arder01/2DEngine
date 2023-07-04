#pragma once
#include "Point.h"
#include "SDL.h"
#include  "Vector2d.h"
#include "Engine.h"
class Camera
{
public:

	void Update(float dt); 
	inline static Camera* GetInstance() { return s_Instance = (s_Instance != nullptr) ? s_Instance : new  Camera(); }
	
	inline SDL_Rect GetViewBox() { return m_ViewBox; }
	inline Vector2d GetPosition() { return m_Position; }
	inline void SetTarget(Point* target) { m_Target = target; }


private:
	Camera() { m_ViewBox = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT }; }
	Point* m_Target;
	Vector2d m_Position;

	SDL_Rect m_ViewBox;
	static Camera* s_Instance;

};

