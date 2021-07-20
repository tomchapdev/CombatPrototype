#pragma once

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
}

struct Player
{
	int health = GC::PLAYER_HEALTH;
	float speed = GC::PLAYER_SPEED;
};

struct Enemy
{
	bool alive;
	int health = GC::ENEMY_HEALTH;
	float speed = GC::ENEMY_SPEED;
};