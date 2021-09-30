#include "Map.h"
Map::Map(int id, LPCWSTR filePath_texture, LPCWSTR filePath_data, int num_row_on_texture, int num_col_on_texture, int num_row_on_tilemap, int num_col_on_tilemap, int tileset_width, int tileset_height)
{

	this->filePath_texture = filePath_texture;
	this->filePath_data = filePath_data;

	this->num_row_on_texture = num_row_on_texture;
	this->num_col_on_texture = num_col_on_texture;
	this->num_row_on_tilemap = num_row_on_tilemap;
	this->num_col_on_tilemap = num_col_on_tilemap;
	this->tileset_width = tileset_width;
	this->tileset_height = tileset_height;
	LoadResources();
}

void Map::LoadResources()
{
	//load id map
	DebugOut(L"[INFO] Start loading map resources from : %s \n", filePath_data);

	ifstream fs(filePath_data, ios::in);

	if (fs.fail())
	{
		DebugOut(L"[ERROR] TileMap::Load_MapData failed: ID=%d", id);
		fs.close();
		return;
	}

	for (int i = 0; i < num_row_on_tilemap; i++)
	{
		for (int j = 0; j < num_col_on_tilemap; j++)
			fs >> map[i][j];
	}

	fs.close();

	DebugOut(L"[INFO] Done loading map resources %s\n", filePath_data);
	//load texmap
	CTextures* textures = CTextures::GetInstance();

	textures->Add(id, filePath_texture);//, D3DCOLOR_XRGB(255, 0, 255));

	LPTEXTURE texMap = textures->Get(id);


	int id_sprite = 1;
	for (UINT i = 0; i < num_row_on_texture; i++)
	{
		for (UINT j = 0; j < num_col_on_texture; j++)
		{
			int id_SPRITE = id + id_sprite;
			sprites->Add(id_SPRITE, tileset_width * j, tileset_height * i, tileset_width * (j + 1), tileset_height * (i + 1), texMap);
			id_sprite = id_sprite + 1;
		}
	}
}

void Map::Render()
{
	int firstcol = 0 / tileset_width;
	int lastcol = firstcol + (800 / tileset_width);
	for (UINT i = 0; i < 27; i++)
	{
		for (UINT j = 0; j <= lastcol; j++)
		{
			float x = tileset_width * (j - firstcol);
			if (x != 0)
				x = tileset_width * (j - firstcol) + 0.5;
			float y = tileset_height*i;
			if (y != 0)
				y = tileset_height * i - 0.5;
			sprites->Get(map[i][j] + id)->Draw(x, y);
		}
	}
}

Map::~Map()
{
}
