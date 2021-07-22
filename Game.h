#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <Windows.h>


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

//global constants
namespace GC
{
	//game play related constants to tweak
	const Dim2Di SCREEN_RES{ 768, 768 };	//game window dimensions
	const float SPRITE_SCALE = 3.0f;		//scale final sprite by this
	const int TILESIZE = 16;
	const int SCALED_TILE = (int)(SPRITE_SCALE * TILESIZE);
	const int FRAMERATE_MAX = 60;
	const char KEY_ESCAPE = 27;
	const char KEY_W = 57;
	const char KEY_A = 41;
	const char KEY_S = 53;
	const char KEY_D = 44;
	const char BACKSPACE_KEY = 8;
	const char ENTER_KEY = 13;
	const int PLAYER_HEALTH = 6;
	const float PLAYER_SPEED = 128.f;
	const int PLAYER_FRAMES = 9;
	const int ENEMY_HEALTH = 1;
	const float ENEMY_SPEED = 128.f;
	const int ENEMY_NUM = 6;
	const float ENEMY_KNOCKBACK = 128.f;
	const int ROOM_SIZE = 16;
	const int ROOM_NUM = 4;
	const int TILE_NUM = 25;
	const int WALL_HEAD = 4;
	const int WALL_WIDTH = 5;
	const float ATTACK_SWEEP = 90.f;
	const float PI = 3.1415926f;
	const float SWORD_HOVER = 1.f * (float)(GC::SCALED_TILE);

	const int roomList[GC::ROOM_NUM][GC::ROOM_SIZE][GC::ROOM_SIZE] = {
		//startRoom
	{   {-1,-1,-1,-1, 7, 6, 6, 6, 6, 6, 6, 8,-1,-1,-1,-1},
		{-1,-1,-1,-1, 2, 1, 1, 1, 1, 1, 1, 3,-1,-1,-1,-1},
		{-1,-1,-1,-1,11, 0, 0, 0, 0, 0, 0,12,-1,-1,-1,-1},
		{ 7, 6, 6, 6,11, 0, 0, 0, 0, 0, 0,12, 6, 6, 6, 8},
		{ 2, 1, 1, 1,24, 0, 0, 0, 0, 0, 0,23, 1, 1, 1, 3},
		{11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12},
		{11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12},
		{11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12},
		{11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12},
		{11, 6, 6, 8, 0, 0, 0, 0, 0, 0, 0, 0, 7, 6, 6,12},
		{ 4, 1, 1, 1,11, 0, 0, 0, 0, 0, 0,12, 1, 1, 1, 5},
		{-1,-1,-1,-1,11, 0, 0, 0, 0, 0, 0,12,-1,-1,-1,-1},
		{-1,-1,-1,-1,11, 0, 0, 0, 0, 0, 0,12,-1,-1,-1,-1},
		{-1,-1,-1,-1,11, 0, 0, 0, 0, 0, 0,12,-1,-1,-1,-1},
		{-1,-1,-1,-1,11, 6, 6,15, 0, 6, 6,12,-1,-1,-1,-1},
		{-1,-1,-1,-1, 4, 1, 1,16, 0, 1, 1, 5,-1,-1,-1,-1}},

		//enemyRoom1
	{   { 7, 6, 6, 6, 6, 6, 6,13,-1, 6, 8,-1,-1,-1,-1,-1},
		{ 2, 1, 1, 1, 1, 1, 1,14,-1, 1, 3,-1,-1,-1,-1,-1},
		{11, 0, 0, 0, 0, 0, 0, 0, 0, 0,11, 6,15,-1, 6, 8},
		{11, 0,22, 0, 0, 0, 0, 0, 0, 0, 4, 1,16, 0, 1, 3},
		{11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12},
		{11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,22, 0,12},
		{11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12},
		{11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12},
		{11, 0, 0, 0, 0, 0, 0, 0,22, 0, 0, 0, 0, 0, 0,12},
		{11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12},
		{11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12},
		{11, 0,22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,22, 0,12},
		{11, 0, 0, 0, 0, 0, 0,22, 0, 0, 0, 0, 0, 0, 0,12},
		{11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12},
		{11, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,12},
		{ 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5}},
		//enemyRoom2
	{   {-1,-1,-1,-1,-1, 7, 6,15, 6, 6, 6, 6, 6, 6, 6, 8},
		{-1,-1,-1,-1,-1, 2, 1,16, 0,1, 1, 1, 1, 1, 1, 3},
		{ 7, 6,13,-1, 6,11, 0, 0, 0, 0, 0, 0, 0, 0, 0,12},
		{ 2, 1,14, 0, 1,11, 0, 0, 0, 0, 0, 0, 0, 0, 0,12},
		{11, 0, 0, 0, 0,11, 0, 0, 0, 0, 0, 0, 0, 0, 0,12},
		{11, 0, 0, 0, 0,11, 0, 0, 0, 0, 0, 0, 0, 0, 0,12},
		{11, 0, 0, 0, 0,11, 0, 0, 0, 0, 0, 0, 0, 0, 0,12},
		{11, 0, 0, 0, 0,11, 0, 0, 0, 0, 0, 0, 0, 0, 0,12},
		{11, 0, 0, 0, 0,11, 0,22, 0,22, 0, 0, 0, 0, 0,12},
		{11, 0, 0, 0, 0,11, 6, 6, 6, 6, 6, 6,21, 0, 0,12},
		{11, 0, 0, 0, 0, 4, 1, 1, 1, 1, 1, 1,19, 0, 0,12},
		{11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12},
		{11, 0,22,22, 0, 0, 0, 0,22, 0, 0, 0, 0,22, 0,12},
		{11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12},
		{11, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,12},
		{ 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5}},
		//enemyRoom3
	{   { 7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 8},
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
		{11, 0, 0, 0, 0, 0, 0, 0, 0,10,11, 0, 0, 0, 0,10},
		{11, 6, 6, 6, 6, 6,13, 0, 6,10,11, 6,15, 0, 6,10},
		{ 4, 1, 1, 1, 1, 1,14, 0, 1, 5, 4, 1,16, 0, 1, 5}} };

	
	const sf::IntRect tileList[GC::TILE_NUM] = {
	//	0 floor					1 wallMiddle
		{ 16, 64, 16, 16 },		{ 32, 16, 16, 16 },
	//	2 wallTopLeft			3 wallTopRight
		{ 32, 128, 16, 16 },	{ 48, 128, 16, 16 },
	//	4 wallBottomLeft		5 wallBottomRight
		{ 32, 160, 16, 16 },	{ 48, 160, 16, 16 },
	//	6 wallHeadMiddle		7 wallHeadTopLeft
		{ 32, 12, 16, 4 },		{ 32, 124, 16, 4 },
	//	8 wallHeadTopRight		9 wallHeadBottomLeft
		{ 48, 124, 16, 4 },		{ 32, 144, 16, 16 },
	//	10 wallHeadBottomRight	11 wallLeft
		{ 48, 144, 16, 16 },	{ 16, 128, 5, 16 },
	//	12 wallRight			13 doorOpenTop
		{ 11, 128, 5, 16 },		{ 80, 224, 32, 16 },
	//	14 doorOpenBottom		15 doorClosedTop
		{ 80, 240, 32, 16 },	{ 32, 224, 32, 16 },
	//	16 doorClosedBottom		17 !!!!!freeTile!!!!!
		{ 32, 240, 32, 16 },	{ 0, 0, 0, 0 },
	//	18 wallMiddleLeft		19 wallMiddleRight
		{ 16, 16, 16, 16 },		{ 16, 16, 16, 16 },
	//	20 wallHeadMiddleLeft	21 wallHeadMiddleRight
		{ 16, 12, 16, 4 },		{ 16, 12, 16, 4 },
	//	22 Spawner				23 wallBottomMiddleRight
		{ 16, 64, 16, 16 },		{ 11, 144, 5, 16},
	//	24 wallBottomMiddleLeft
		{ 16, 144, 5, 16}
	};

	const sf::IntRect ENEMY_TILES1 = { 368, 48, 128, 16 };
}

struct PlayerAttack
{
	float start = 0.f;
	float end = 0.f;
};

struct Player
{
	int health = GC::PLAYER_HEALTH;
	float speed = GC::PLAYER_SPEED;
	bool movingUp = false;
	bool movingDown = false;
	bool movingLeft = false;
	bool movingRight = false;
	bool nextRoom = false;
	bool attacking = false;
	float aimRotation = 0.f;
	float swRotation = 0.f;
	PlayerAttack attack;
	sf::Mouse mouse;

	//sf::IntRect frames[GC::PLAYER_FRAMES];
	//int frame = 0;
	sf::Texture tex;
	sf::Sprite sprite;
	sf::Texture swTex;
	sf::Sprite swSprite;

	//initialise player
	void Init(sf::Image spritesheet);
	//handle player input
	void Update();
	//player map collision
	void CheckMapCollision(const int collisionMap[GC::TILESIZE][GC::TILESIZE]);
	//move player
	void Move(float elapsed);
	//player attack
	void Attack();
	//render player
	void Render(sf::RenderWindow& window);
};

struct Enemy
{
	bool alive = false;
	bool attack = false;
	bool knockback = false;
	float knock[3] = { 0.f, 0.f, 0.f};
	int health = 0;
	float speed = GC::ENEMY_SPEED;

	sf::Texture tex;
	sf::Sprite spr;

	//initialise enemy
	void Init(sf::Image spritesheet);
	//enemy movement
	void Movement(Player player, float elapsed);
	//enemy attack
	void Attack(Player& player);
	//knock enemy back
	void Knockback(float elapsed);
	//enemy render
	void Render(sf::RenderWindow& window);
};

struct Room
{
	int ID = -1;
	bool cleared = false;
	int numEnemies = GC::ENEMY_NUM;
	int deadEnemies = 0;
	Dim2Di entrance{ 0,0 };
	Dim2Di exit = { 0,0 };
	sf::Texture baseTexture;
	std::vector<Dim2Di> spawners;

	//initialise room
	void Init(sf::Image spritesheet, int id);
	//close doors
	//void Enter();
	//open doors
	void Cleared(sf::Image spritesheet);
	//render door tops over player
	void RenderDoorTops(sf::RenderWindow& window, sf::Image spritesheet);
};

struct Map
{
	//texture of current room
	sf::Texture roomTex;
	//current room sprite
	sf::Sprite spr;
	//current room
	int currentRoom = 0;
	//collision map
	int collisionMap[GC::ROOM_SIZE][GC::ROOM_SIZE] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };

	//enemy list
	std::vector<Enemy> enemies;

	//initialises map
	void Init(sf::Image spritesheet, sf::Texture rTex);
	//changes collision map
	void GetCollisionMap();
	//alter collision map
	void RoomCleared(Room room);
	//render current room
	void Render(sf::RenderWindow& window);
	//change the active room
	void NextRoom(Room room, Player& player);
	//spawn enemies
	void SpawnEnemies(Room room);
	//handles enemy AI
	void UpdateEnemies(Player& player, float elapsed);
};

bool LoadTexture(const std::string& file, sf::Texture& tex);
/*
Send text to the debug output window
Second parameter can be ignored
*/
void DebugPrint(const std::string& mssg1, const std::string& mssg2 = "");