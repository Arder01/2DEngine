#pragma once
#include "Layer.h"
#include <string>
#include <vector>

struct TileSet {
	int FirstId, LastId;
	int RowCount, ColCount;
	int TileCount, TileSize;
	std::string Name, Source;
};

using TileSetList = std::vector<TileSet>;
using TileMap = std::vector<std::vector<int>>;


class TileLayer :public Layer
{
public:
	TileLayer(int tilesize, int rowcount, int colcount, TileMap tilemap, TileSetList tilesets);
	virtual void Render();
	virtual void Update();
	inline TileMap GetTileMap() { return m_TileMap; }
private:
	int m_TileSize;
	int m_RowCount, m_ColCount;
	TileMap m_TileMap;
	TileSetList  m_TileSets;
};

