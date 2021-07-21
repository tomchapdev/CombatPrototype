#pragma once
#include <vector>
#include <string>
#include <iostream>
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
	const int ENEMY_NUM = 6;
	const int ROOM_SIZE = 16;
	const int TILE_NUM = 23;
	const int TILESIZE = 16;
	const int WALL_TOP = 4;
}

//all rooms, game structs
namespace GameObjects
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
													{11, 0, 0, 0, 0, 0, 0,22, 0, 0, 0, 0, 0, 0, 0,10},
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

	//spawns the player into start room
	void Init();
	//player movement
	void Movement();
	//player attack
	void Attack();
};

struct Enemy
{
	bool alive = false;
	int health = GC::ENEMY_HEALTH;
	float speed = GC::ENEMY_SPEED;
	Dim2Di pos = { 0, 0 };
};

struct Room
{
	int ID = -1;
	int tilemap[16][16];
	Enemy enemyList[6];
	bool alive = false;
	int deadEnemies = 0;
	Dim2Di entrance;
	Dim2Di exit;

	//initialise room, generate enemies
	void Init();
	//enter room
	void Enter();
	//exit room
	void Exit();
};

typedef struct Tile
{
	IntRect r;
	int ID;
	sf::Sprite spr;
};

typedef struct Map
{
	sf::Texture spritesheet;
	vector<Tile> tiles{};
	vector<Room> rooms{};
	int activeRoom = 0;

	//initialise tilemap
	void Init();
	//generate map
	void GenerateMap();
	//render current room
	void Render(sf::RenderWindow& window, float elapsed);
};

bool LoadTexture(const string& file, Texture& tex);