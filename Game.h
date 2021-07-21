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
	const Dim2Di SCREEN_RES{ 768, 768 };	//game window dimensions
	const float SPRITE_SCALE = 4.0f;		//Scale final sprite by this
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
	int roomList[4][GC::ROOM_SIZE][GC::ROOM_SIZE] = {
			//startRoom
		{   {-1,-1,-1,-1, 7, 6, 6, 6, 6, 6, 6, 8,-1,-1,-1,-1},
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
			{-1,-1,-1,-1, 4, 1,13,16,16,14, 1, 5,-1,-1,-1,-1} },
			//EnemyRoom1
		{   { 7, 6, 6, 6, 6, 6, 6,-1,-1, 6, 8,-1,-1,-1,-1,-1},
			{ 2, 1, 1, 1, 1, 1, 1,17,17, 1, 3,-1,-1,-1,-1,-1},
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
			{ 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5} },
			//EnemyRoom2
		{   {-1,-1,-1,-1,-1, 6, 6,-1,-1, 6, 6, 6, 6, 6, 6, 8},
			{-1,-1,-1,-1,-1,11, 1,16,16, 1, 1, 1, 1, 1, 1, 3},
			{ 7,-1,-1,-1,-1,11, 0, 0, 0, 0, 0, 0, 0, 0, 0,12},
			{ 2,13,17,17,14,11, 0, 0, 0, 0, 0, 0, 0, 0, 0,12},
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
			{ 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5} },
			//EnemyRoom3
		{   {7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 8},
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
			{ 4, 1, 1, 1, 1,13,17,17,14, 5, 4,13,16,16,14, 5} } };

}

struct Player
{
	int health = GC::PLAYER_HEALTH;
	float speed = GC::PLAYER_SPEED;
	sf::Sprite spr = sf::Sprite();

	//player movement
	//void Movement();
	//player attack
	//void Attack();
};

struct Enemy
{
	bool alive = false;
	int health = GC::ENEMY_HEALTH;
	float speed = GC::ENEMY_SPEED;
	Dim2Di pos = { 0,0 };
	sf::Sprite spr = sf::Sprite();


	//enemy movement
	//void Movement();
	//enemy attack
	//void Attack();
};

struct Tile
{
	//rect of sprite
	sf::IntRect r = sf::IntRect();
	//sprite for rendering
	sf::Sprite spr = sf::Sprite();
};

struct Room
{
	int ID = -1;
	bool active = false;
	int numEnemies = GC::ENEMY_NUM;
	int deadEnemies = 0;
	Dim2Di entrance{ 0,0 };
	Dim2Di exit = { 0,0 };
	sf::Texture baseTexture = sf::Texture();
	//close doors
	//void Enter();
	//open doors
	//void Clear(Map map);
};

struct Map
{
	//texture of current room
	sf::Texture roomTex = sf::Texture();
	//current room sprite
	sf::Sprite spr = sf::Sprite();
	//current room
	int currentRoom = 0;
	//active enemies
	std::vector<Enemy> enemies;
	//render current room
	void Render(sf::RenderWindow& window, float elapsed, std::vector<Room> rooms);
	//change the active room
	//void NextRoom(std::vector<Room> rooms);
};

bool LoadTexture(const std::string& file, sf::Texture& tex);