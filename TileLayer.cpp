#include "TileLayer.h"
#include "TextureManager.h"

TileLayer::TileLayer(int tilesize, int rowcount, int colcount, TileMap tilemap, TileSetList tilesets) : m_TileSets(tilesets), m_ColCount(colcount), m_TileMap(tilemap),m_TileSize(tilesize),m_RowCount(rowcount)
{
	for (unsigned int i = 0; i < m_TileSets.size(); i++) {
		TextureManager::GetInstance()->Load(m_TileSets[i].Name, "Assets/Maps/" + m_TileSets[i].Source);
	}
}

void TileLayer::Render()
{
	for (unsigned int i = 0; i < m_RowCount; i++) {
		for (unsigned int j = 0; j < m_ColCount; j++) {
			int tileID = m_TileMap[i][j];
			if (tileID == 0)
				continue;
			else {
				int index=0;
				if (m_TileSets.size() > 1) {
					for (unsigned int k = 1; k < m_TileSets.size(); k++) {
						if (tileID > m_TileSets[k].FirstId && tileID < m_TileSets[k].LastId) {
							tileID = tileID + m_TileSets[k].TileCount - m_TileSets[k].LastId;
							index = k;
							break;
						}
					}
				}
				TileSet ts = m_TileSets[index];
				int tileRow = tileID / ts.ColCount;
				int tileCol = tileID - tileRow * ts.ColCount - 1;

				//if (tileID % ts.ColCount == 0) {
				//	tileRow--;
				//	tileCol = ts.ColCount - 1;
				//}
				TextureManager::GetInstance()->DrawTile(ts.Name, ts.TileSize, j * ts.TileSize, i * ts.TileSize, tileRow, tileCol);
			}
		}
	}
}
void TileLayer::Update()
{

}