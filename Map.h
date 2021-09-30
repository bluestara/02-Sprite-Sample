#pragma once
#include "Sprites.h"
#include "Textures.h"
#include "debug.h"
#include "Game.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class Map
{
	static Map* __instance;
	LPCWSTR filePath_data;
	LPCWSTR filePath_texture;
	int num_row_on_tilemap, num_col_on_tilemap;
	int num_row_on_texture, num_col_on_texture;
	int tileset_width, tileset_height;
	int id;
	int map[300][300];
public:
	CSprites* sprites = CSprites::GetInstance();
	Map();
	void Load(int id, LPCWSTR filePath_texture, LPCWSTR filePath_data, int num_row_on_texture, int num_col_on_texture, int num_row_on_tilemap, int num_col_on_tilemap, int tileset_width, int tileset_height);
	void LoadResources();
	void Render();
	static Map* GetInstance();
	~Map();
};

