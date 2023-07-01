#pragma once
#include "Character.h"
#include "Animation.h"


class Warrior: public Character
{
public:
	Warrior(Properties* props);

	virtual void Draw() ;
	virtual void Clean() ;
	virtual void Update(float dt) ;

private:
	Animation* m_Animation;
};

