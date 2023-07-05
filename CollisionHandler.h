#pragma once
#include "SDL.h"
#include <vector>
#include "TileLayer.h"
#include "GameMap.h"

class CollisionHandler
{
public:
	bool CheckCollisioin(SDL_Rect a, SDL_Rect b);
	bool MapCollision(SDL_Rect a);
	inline static CollisionHandler* GetInstance() { return s_Instance = (s_Instance != nullptr) ? s_Instance : new CollisionHandler(); }

private:
	CollisionHandler();
	TileMap m_CollisionTileMap;
	TileLayer* m_CollisionLayer;
	static CollisionHandler* s_Instance;
};

