#include "MapParser.h"

MapParser* MapParser::s_Instance = nullptr;

bool MapParser::Load()
{
	if (!Parse("Map", "Assets/Maps/Map.tmx"))
		return false; 
	else
		return true;
}

bool MapParser::Parse(std::string id, std::string source)
{
	TiXmlDocument xml;
	xml.LoadFile(source);
	if (xml.Error())
	{
		std::cerr << "Failed to Load: " << source << std::endl;
		return false;
	}
	TiXmlElement* root = xml.RootElement();
	int rowcount, colcount, tilesize = 0;
	root->Attribute("width", &colcount);
	root->Attribute("height", &rowcount);
	root->Attribute("tilewidth", &tilesize);
	TileSetList tilesets;
	for (TiXmlElement* e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
		if (e->Value() == std::string("tileset")) {
			tilesets.push_back(ParseTileSet(e));
		}
	}
	GameMap* gamemap = new GameMap();
	for (TiXmlElement* e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
		if (e->Value() == std::string("layer")) {
			TileLayer* tilelayer = ParseTileLayer(e, tilesets, tilesize, rowcount, colcount);
			gamemap->m_MapLayer.push_back(tilelayer);
		}
	}
	m_MapDicts[id] = gamemap;
	return true;
}

TileSet MapParser::ParseTileSet(TiXmlElement* xmlTileSet)
{
	TileSet tileset;
	tileset.Name = xmlTileSet->Attribute("name");
	xmlTileSet->Attribute("firstgid", &tileset.FirstId);
	xmlTileSet->Attribute("tilecount", &tileset.TileCount);
	tileset.LastId = (tileset.FirstId + tileset.TileCount) - 1;
	xmlTileSet->Attribute("columns", &tileset.ColCount);
	tileset.RowCount = tileset.TileCount / tileset.ColCount;
	xmlTileSet->Attribute("tilewidth", &tileset.TileSize);

	TiXmlElement* image = xmlTileSet->FirstChildElement();
	tileset.Source = image->Attribute("source");
	return tileset;
}

TileLayer* MapParser::ParseTileLayer(TiXmlElement* xmlLayer, TileSetList tilesets, int tilesize, int rowcount, int colcount)
{
	TiXmlElement* data = nullptr;
	for (TiXmlElement* e = xmlLayer->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("data"))
		{
			data = e;
			break;
		}
	}
	std::string matrix(data->GetText());
	std::istringstream iss(matrix);
	std::string id;

	TileMap tilemap(rowcount, std::vector<int>(colcount, 0));
	for (int row = 0; row < rowcount; row++) {
		for (int col = 0; col < colcount; col++) {
			std::getline(iss, id, ',');
			std::stringstream convertor(id);
			convertor >> tilemap[row][col];

			if (!iss.good()) 
				break;
		}
	}
	return (new TileLayer(tilesize, rowcount, colcount, tilemap, tilesets));
}
void MapParser::Clean()
{
	std::map<std::string, GameMap*>::iterator it;
	for (it = m_MapDicts.begin(); it != m_MapDicts.end(); it++)
		it->second = nullptr;

	m_MapDicts.clear();
}