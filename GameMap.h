#pragma once
#include <vector>
#include "Layer.h"
class GameMap
{
public:
	GameMap() {}

	void Render() {
		for (unsigned int i = 0; i < m_MapLayer.size(); i++)
			m_MapLayer[i]->Render();
	}
	void Update() {
		for (unsigned int i = 0; i < m_MapLayer.size(); i++)
			m_MapLayer[i]->Update();//this Update is Layer->Update() so no infinite loop of calling  GameMap->Update
	}

std::vector<Layer*> GetMapLayer() { return m_MapLayer; }

private:
	friend class MapParser;
	std::vector<Layer*> m_MapLayer;

};