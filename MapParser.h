#pragma once
#include  "TinyXml/tinyxml.h"
#include <map>
#include <string>
#include "GameMap.h"
#include "TileLayer.h"


class MapParser
{
public:
	bool Load();
	void Clean();

	inline GameMap* GetMap(std::string id) { return m_MapDicts[id]; }
	inline static MapParser* GetInstance() { return s_Instance = (s_Instance != nullptr) ? s_Instance : new MapParser(); }

private:
	bool Parse(std::string id, std::string source);
	TileSet ParseTileSet(TiXmlElement* xmlTileSet);
	TileLayer* ParseTileLayer(TiXmlElement* xmlLayer, TileSetList tilesets, int tilesize, int rowcount, int colcount);
private:
	MapParser() {}
	static MapParser* s_Instance;
	std::map<std::string, GameMap*> m_MapDicts;
};

