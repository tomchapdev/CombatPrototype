#pragma once
#include <vector>
#include <string>
#include "SFML/Graphics.hpp"


//dimensions in 2D as int
struct Dim2Di
{
	int x, y;
};

//dimensions in 2D as float
struct Dim2Df
{
	float x, y;
};

//Global constants
namespace GC
{
	//game play related constants to tweak
	const Dim2Di SCREEN_RES{ 1280, 720 };	//game window dimensions
	const float SPRITE_SCALE = 2.0f;		//Scale final sprite by this
	const int FRAMERATE_MAX = 60;			//maximum framerate
	const char ESCAPE_KEY = 27;
	const char BACKSPACE_KEY = 8;
	const char ENTER_KEY = 13;
	const int PLAYER_HEALTH = 6;
	const float PLAYER_SPEED = 16.f;
	const int ENEMY_HEALTH = 1;
	const float ENEMY_SPEED = 16.f;
	const int ROOM_SIZE = 16;
	const int TILE_NUM = 12;
	const int TILESIZE = 16;
	const int WALL_TOP = 4;
	const Dim2Di WALL = { TILESIZE, TILESIZE + WALL_TOP };
}

namespace BuiltRooms
{
	int startRoom[GC::ROOM_SIZE][GC::ROOM_SIZE] = { {-1,-1,-1,-1, 7, 6, 6, 6, 6, 6, 6, 8,-1,-1,-1,-1},
													{-1,-1,-1,-1, 2, 1, 1, 1, 1, 1, 1, 3,-1,-1,-1,-1},
													{-1,-1,-1,-1,11, 0, 0, 0, 0, 0, 0,12,-1,-1,-1,-1},
													{ 7, 6, 6, 6,11, 0, 0, 0, 0, 0, 0,12, 6, 6, 6, 8},
													{ 2, 1, 1, 1, 5, 0, 0, 0, 0, 0, 0, 4, 1, 1, 1, 3},
													{11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10},
													{11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10},
													{11, 0, 0, 0, 0, 0, 0,22, 0, 0, 0, 0, 0, 0, 0,10},
													{11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10},
													{11, 6, 6, 6, 8, 0, 0, 0, 0, 0, 0, 7, 6, 6, 6,10},
													{ 4, 1, 1, 1, 3, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 5},
													{-1,-1,-1,-1,11, 0, 0, 0, 0, 0, 0,10,-1,-1,-1,-1},
													{-1,-1,-1,-1,11, 0, 0, 0, 0, 0, 0,10,-1,-1,-1,-1},
													{-1,-1,-1,-1,11, 0, 0, 0, 0, 0, 0,10,-1,-1,-1,-1},
													{-1,-1,-1,-1, 4, 1,13,16,16,14, 1, 5,-1,-1,-1,-1}};

	int EnemyRoom1[GC::ROOM_SIZE][GC::ROOM_SIZE] = {{ 7, 6, 6, 6, 6, 6, 6,-1,-1, 6, 8,-1,-1,-1,-1,-1},
													{ 2, 1, 1, 1, 1, 1, 1,16,16, 1, 3,-1,-1,-1,-1,-1},
													{11, 0, 0, 0, 0, 0, 0, 0, 0, 0,11,-1,-1,-1,-1, 8},
													{11, 0,22, 0, 0, 0, 0, 0, 0, 0, 4,13,16,16,14, 3},
													{11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10},
													{11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,22, 0,10},
													{11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10},
													{11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10},
													{11, 0, 0, 0, 0, 0, 0, 0,22, 0, 0, 0, 0, 0, 0,10},
													{11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10},
													{11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10},
													{11, 0,22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,22, 0,10},
													{11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10},
													{11, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,10},
													{ 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5}};

	int EnemyRoom2[GC::ROOM_SIZE][GC::ROOM_SIZE] = {{-1,-1,-1,-1,-1, 6, 6,-1,-1, 6, 6, 6, 6, 6, 6, 8},
													{-1,-1,-1,-1,-1,11, 1,16,16, 1, 1, 1, 1, 1, 1, 3},
													{ 7,-1,-1,-1,-1,11, 0, 0, 0, 0, 0, 0, 0, 0, 0,12},
													{ 2,13,16,16,14,11, 0, 0, 0, 0, 0, 0, 0, 0, 0,12},
													{11, 0, 0, 0, 0,11, 0, 0, 0, 0, 0, 0, 0, 0, 0,12},
													{11, 0, 0, 0, 0,11, 0, 0, 0, 0, 0, 0, 0, 0, 0,12},
													{11, 0, 0, 0, 0,11, 0, 0, 0, 0, 0, 0, 0, 0, 0,12},
													{16, 0, 0, 0, 0,11, 0, 0, 0, 0, 0, 0, 0, 0, 0,12},
													{16, 0, 0, 0, 0,11, 0,22, 0,22, 0, 0, 0, 0, 0,12},
													{11, 0, 0, 0, 0,11, 0, 6, 6, 6, 6, 6,21, 0, 0,12},
													{11, 0, 0, 0, 0, 4, 1, 1, 1, 1, 1, 1,19, 0, 0,12},
													{11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12},
													{11, 0,22,22, 0, 0, 0, 0,22, 0, 0, 0, 0,22, 0,12},
													{11, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,12},
													{ 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5}};

	int EnemyRoom3[GC::ROOM_SIZE][GC::ROOM_SIZE] = {{ 7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 8},
													{ 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3},
													{11, 0, 0, 0,22, 0, 0, 0, 0,22, 0, 0, 0, 0, 0,12},
													{11, 0, 0, 2, 6, 6, 6, 6, 6, 6, 8, 0, 0, 0, 0,12},
													{11, 0, 0, 7, 1, 1, 1, 1, 1, 1, 3, 0, 0, 0, 0,12},
													{11, 0, 0,11,-1,-1,-1,-1,-1,-1,11, 0, 0, 0, 0,12},
													{11, 0, 0,11,-1,-1,-1,-1,-1,-1,11, 0, 0, 0, 0,12},
													{11, 0, 0,11,-1,-1,-1,-1,-1,-1,11, 0, 0, 0, 0,12},
													{11, 0, 0,11,-1,-1,-1,-1,-1,-1,11, 0, 0, 0, 0,12},
													{11, 0, 0,11, 6, 6, 6, 6, 6, 8,11, 0, 0, 0, 0,12},
													{11, 0, 0, 4, 1, 1, 1, 1, 1, 3,11, 0, 0, 0, 0,12},
													{11, 0,22, 0, 0, 0, 0, 0, 0,10,11, 0, 0, 0,22,12},
													{11, 0,22, 0, 0, 0, 0, 0, 0,10,11,22, 0, 0, 0,12},
													{11, 6, 6, 6, 6, 6, 6, 0, 0,10,11, 0, 0, 0, 0,10},
													{ 4, 1, 1, 1, 1,13,16,16,14, 5, 4,13,16,16,14, 5}};
}

struct Player
{
	int health = GC::PLAYER_HEALTH;
	float speed = GC::PLAYER_SPEED;

	void Movement();
};

void Player::Movement()
{

}

struct Enemy
{
	bool alive;
	int health = GC::ENEMY_HEALTH;
	float speed = GC::ENEMY_SPEED;
};

struct Room
{
	int tilemap[GC::ROOM_SIZE][GC::ROOM_SIZE];
	vector<Enemy> enemies;
	Dim2Di entrance;
	Dim2Di exit;
};

struct Tile
{
	//int left, right, x, y;
	string name;
	int ID;
	sf::Sprite spr;
};

struct Map
{
	Texture spritesheet;
	vector<Tile> tiles;
	vector<Room> rooms;

	//initialise tilemap
	void Init();
	//generate map
	void GenerateMap();
};

void Map::Init()
{
	LoadTexture("data/spritesheet.png", spritesheet);
	tiles.insert(tiles.begin(), 16, Tile());
	for (int i = 0; i < tiles.size(); i++)
	{
		tiles[i].ID = i;
	}
	tiles[0].name = "floor";
	tiles[0].spr.setTexture(tilemap);
	tiles[0].rect = { 16, 64, 16, 16 };
	tiles[0].spr.setTextureRect(tiles[0].rect);

	tiles[1].name = "wallMiddle";
	tiles[1].spr.setTexture(tilemap);
	tiles[1].rect = { 32, 16, 16, 16 };
	tiles[1].spr.setTextureRect(tiles[1].rect);

	tiles[2].name = "wallTopLeft";
	tiles[2].spr.setTexture(tilemap);
	tiles[2].rect = { 32, 128, 16, 16 };
	tiles[2].spr.setTextureRect(tiles[2].rect);

	tiles[3].name = "wallTopRight";
	tiles[3].spr.setTexture(tilemap);
	tiles[3].rect = { 48, 128, 16, 16 };
	tiles[3].spr.setTextureRect(tiles[3].rect);

	tiles[4].name = "wallBottomLeft";
	tiles[4].spr.setTexture(tilemap);
	tiles[4].rect = { 32, 160, 16, 16 };
	tiles[4].spr.setTextureRect(tiles[4].rect);

	tiles[5].name = "wallBottomRight";
	tiles[5].spr.setTexture(tilemap);
	tiles[5].rect = { 48, 160, 16, 16 };
	tiles[5].spr.setTextureRect(tiles[5].rect);

	tiles[6].name = "wallHeadMiddle";
	tiles[6].spr.setTexture(tilemap);
	tiles[6].rect = { 32, 0, 16, 16 };
	tiles[6].spr.setTextureRect(tiles[6].rect);

	tiles[7].name = "wallHeadTopLeft";
	tiles[7].spr.setTexture(tilemap);
	tiles[7].rect = { 32, 112, 16, 16 };
	tiles[7].spr.setTextureRect(tiles[7].rect);

	tiles[8].name = "wallHeadTopRight";
	tiles[8].spr.setTexture(tilemap);
	tiles[8].rect = { 48, 112, 16, 16 };
	tiles[8].spr.setTextureRect(tiles[8].rect);

	tiles[9].name = "wallHeadBottomLeft";
	tiles[9].spr.setTexture(tilemap);
	tiles[9].rect = { 32, 144, 16, 16 };
	tiles[9].spr.setTextureRect(tiles[9].rect);

	tiles[10].name = "wallHeadBottomRight";
	tiles[10].spr.setTexture(tilemap);
	tiles[10].rect = { 48, 144, 16, 16 };
	tiles[10].spr.setTextureRect(tiles[10].rect);

	tiles[11].name = "wallLeft";
	tiles[11].spr.setTexture(tilemap);
	tiles[11].rect = { 16, 128, 16, 16 };
	tiles[11].spr.setTextureRect(tiles[11].rect);

	tiles[12].name = "wallRight";
	tiles[12].spr.setTexture(tilemap);
	tiles[12].rect = { 0, 128, 16, 16 };
	tiles[12].spr.setTextureRect(tiles[12].rect);

	tiles[13].name = "doorFrameLeft";
	tiles[13].spr.setTexture(tilemap);
	tiles[13].rect = { 16, 224, 16, 32 };
	tiles[13].spr.setTextureRect(tiles[13].rect);

	tiles[14].name = "doorFrameRight";
	tiles[14].spr.setTexture(tilemap);
	tiles[14].rect = {64, 224, 16, 32 };
	tiles[14].spr.setTextureRect(tiles[14].rect);

	tiles[15].name = "doorFrameTop";
	tiles[15].spr.setTexture(tilemap);
	tiles[15].rect = { 32, 221, 32, 3 };
	tiles[15].spr.setTextureRect(tiles[15].rect);

	tiles[16].name = "doorClosed";
	tiles[16].spr.setTexture(tilemap);
	tiles[16].rect = { 32, 244, 32, 32 };
	tiles[16].spr.setTextureRect(tiles[16].rect);

	tiles[17].name = "doorOpen";
	tiles[17].spr.setTexture(tilemap);
	tiles[17].rect = { 80, 244, 32, 32 };
	tiles[17].spr.setTextureRect(tiles[17].rect);

	tiles[18].name = "wallMiddleLeft";
	tiles[18].spr.setTexture(tilemap);
	tiles[18].rect = { 16, 16, 16, 16 };
	tiles[18].spr.setTextureRect(tiles[18].rect);

	tiles[19].name = "wallMiddleRight";
	tiles[19].spr.setTexture(tilemap);
	tiles[19].rect = { 16, 16, 16, 16 };
	tiles[19].spr.setTextureRect(tiles[19].rect);

	tiles[20].name = "wallHeadMiddleLeft";
	tiles[20].spr.setTexture(tilemap);
	tiles[20].rect = { 16, 0, 16, 16 };
	tiles[20].spr.setTextureRect(tiles[20].rect);

	tiles[21].name = "wallHeadMiddleRight";
	tiles[21].spr.setTexture(tilemap);
	tiles[21].rect = { 16, 0, 16, 16 };
	tiles[21].spr.setTextureRect(tiles[21].rect);

	tiles[22].name = "Spawner";
	tiles[22].spr.setTexture(tilemap);
	tiles[22].rect = { 16, 64, 16, 16 };
	tiles[22].spr.setTextureRect(tiles[22].rect);
}

void Map::GenerateMap()
{
	rooms.resize(4);
	rooms[0].tilemap = BuiltRooms::startRoom;
	rooms[0].exit = { 15,7 };
	rooms[1].tilemap = BuiltRooms::EnemyRoom1;
	rooms[1].entrance = { 1,7 };
	rooms[1].exit = { 3,12 };
	rooms[2].tilemap = BuiltRooms::EnemyRoom2;
	rooms[2].entrance = { 3,2 };
	rooms[2].exit = { 1,7 };
	rooms[3].tilemap = BuiltRooms::EnemyRoom3;
	rooms[3].entrance = { 15,6 };
	rooms[3].exit = { 15,12 };
}

bool LoadTexture(const string& file, Texture& tex);