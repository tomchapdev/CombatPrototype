#include <assert.h>
#include <string>
#include "SFML/Graphics.hpp"
#include "Game.h"
#include <vector>

using namespace std;
using namespace sf;
using namespace GameObjects;

Player Init()
{

}

Player Movement()
{

}

Player Attack()
{

}

void Room::Init()
{
	int enemyCounter = 0;
	enemies.insert(enemies.begin(), GC::ENEMY_NUM, Enemy());
	for (int x = 0; x < GC::ROOM_SIZE; x++)
	{
		for (int y = 0; y < GC::ROOM_SIZE; y++)
		{
			if (tilemap[y][x] == 22)
			{
				enemies[enemyCounter].pos = { x, y };
				++enemyCounter;
			}
		}
	}
}

void Room::Enter()
{
	alive = true;
	for (int i = 0; i < GC::ENEMY_NUM; i++)
		enemies[i].alive = true;
}

void Room::Exit() {

}

void Map::Init()
{
	tiles.insert(tiles.begin(), GC::TILE_NUM, Tile());
	for (int i = 0; i < tiles.size(); i++)
	{
		tiles[i].ID = i;
	}
	//"floor";
	tiles[0].spr.setTexture(spritesheet);
	tiles[0].r = { 16, 64, 16, 16 };
	tiles[0].spr.setTextureRect(tiles[0].r);

	//"wallMiddle";
	tiles[1].spr.setTexture(spritesheet);
	tiles[1].r = { 32, 16, 16, 16 };
	tiles[1].spr.setTextureRect(tiles[1].r);

	//"wallTopLeft";
	tiles[2].spr.setTexture(spritesheet);
	tiles[2].r = { 32, 128, 16, 16 };
	tiles[2].spr.setTextureRect(tiles[2].r);

	//"wallTopRight";
	tiles[3].spr.setTexture(spritesheet);
	tiles[3].r = { 48, 128, 16, 16 };
	tiles[3].spr.setTextureRect(tiles[3].r);

	//"wallBottomLeft";
	tiles[4].spr.setTexture(spritesheet);
	tiles[4].r = { 32, 160, 16, 16 };
	tiles[4].spr.setTextureRect(tiles[4].r);

	//"wallBottomRight";
	tiles[5].spr.setTexture(spritesheet);
	tiles[5].r = { 48, 160, 16, 16 };
	tiles[5].spr.setTextureRect(tiles[5].r);

	//"wallHeadMiddle";
	tiles[6].spr.setTexture(spritesheet);
	tiles[6]. = { 32, 0, 16, 16 };
	tiles[6].spr.setTextureRect(tiles[6].r);

	//"wallHeadTopLeft";
	tiles[7].spr.setTexture(spritesheet);
	tiles[7].r = { 32, 112, 16, 16 };
	tiles[7].spr.setTextureRect(tiles[7].re);

	//"wallHeadTopRight";
	tiles[8].spr.setTexture(spritesheet);
	tiles[8].r = { 48, 112, 16, 16 };
	tiles[8].spr.setTextureRect(tiles[8].r);

	//"wallHeadBottomLeft";
	tiles[9].spr.setTexture(spritesheet);
	tiles[9].r = { 32, 144, 16, 16 };
	tiles[9].spr.setTextureRect(tiles[9].r);

	//"wallHeadBottomRight";
	tiles[10].spr.setTexture(spritesheet);
	tiles[10].r = { 48, 144, 16, 16 };
	tiles[10].spr.setTextureRect(tiles[10].r);

	//"wallLeft";
	tiles[11].spr.setTexture(spritesheet);
	tiles[11].r = { 16, 128, 16, 16 };
	tiles[11].spr.setTextureRect(tiles[11].r);

	//"wallRight";
	tiles[12].spr.setTexture(spritesheet);
	tiles[12].r = { 0, 128, 16, 16 };
	tiles[12].spr.setTextureRect(tiles[12].r);

	//"doorFrameLeft";
	tiles[13].spr.setTexture(spritesheet);
	tiles[13].r = { 16, 224, 16, 32 };
	tiles[13].spr.setTextureRect(tiles[13].r);

	//"doorFrameRight";
	tiles[14].spr.setTexture(spritesheet);
	tiles[14].r = { 64, 224, 16, 32 };
	tiles[14].spr.setTextureRect(tiles[14].r);

	//"doorFrameTop";
	tiles[15].spr.setTexture(spritesheet);
	tiles[15].r = { 32, 221, 32, 3 };
	tiles[15].spr.setTextureRect(tiles[15].r);

	//"doorClosed";
	tiles[16].spr.setTexture(spritesheet);
	tiles[16].r = { 32, 244, 32, 32 };
	tiles[16].spr.setTextureRect(tiles[16].r);

	//"doorOpen";
	tiles[17].spr.setTexture(spritesheet);
	tiles[17].r = { 80, 244, 32, 32 };
	tiles[17].spr.setTextureRect(tiles[17].r);

	//"wallMiddleLeft";
	tiles[18].spr.setTexture(spritesheet);
	tiles[18].r = { 16, 16, 16, 16 };
	tiles[18].spr.setTextureRect(tiles[18].r);

	//"wallMiddleRight";
	tiles[19].spr.setTexture(spritesheet);
	tiles[19].r = { 16, 16, 16, 16 };
	tiles[19].spr.setTextureRect(tiles[19].r);

	//"wallHeadMiddleLeft";
	tiles[20].spr.setTexture(spritesheet);
	tiles[20].r = { 16, 0, 16, 16 };
	tiles[20].spr.setTextureRect(tiles[20].r);

	//"wallHeadMiddleRight";
	tiles[21].spr.setTexture(spritesheet);
	tiles[21].r = { 16, 0, 16, 16 };
	tiles[21].spr.setTextureRect(tiles[21].r);

	//"Spawner";
	tiles[22].spr.setTexture(spritesheet);
	tiles[22].r = { 16, 64, 16, 16 };
	tiles[22].spr.setTextureRect(tiles[22].r);
}

void Map::GenerateMap()
{
	rooms.insert(rooms.begin(), 4, Room());
	for (int x = 0; x < 16; x++)
	{
		for (int y = 0; y < 16; y++)
		{
			rooms[0].tilemap[y][x]= GameObjects::startRoom[y][x];
			rooms[1].tilemap[y][x] = GameObjects::EnemyRoom1[y][x];
			rooms[2].tilemap[y][x] = GameObjects::EnemyRoom2[y][x];
			rooms[3].tilemap[y][x] = GameObjects::EnemyRoom3[y][x];
		}
	}
	rooms[0].entrance = { 7,7 };
	rooms[0].exit = { 15,7 };
	rooms[1].entrance = { 1,7 };
	rooms[1].exit = { 3,12 };
	rooms[1].Init();
	rooms[2].entrance = { 3,2 };
	rooms[2].exit = { 1,7 };
	rooms[2].Init();
	rooms[3].entrance = { 15,6 };
	rooms[3].exit = { 15,12 };
	rooms[3].Init();
}

void Map::Render(sf::RenderWindow& window, float elapsed)
{

}

bool LoadTexture(const string& file, Texture& tex)
{
	if (tex.loadFromFile(file))
	{
		tex.setSmooth(true);
		return true;
	}
	assert(false);
	return false;
}