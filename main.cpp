#include <assert.h>
#include <vector>
#include "Game.h"
#include "SFML/Graphics.hpp"

using namespace sf;
using namespace std;

int main()
{
	//forward declarations
	void createTileInfo(vector<Tile>& tiles, Texture spritesheet);
	void createRooms(vector<Room>& rooms);
	void createMap(Map& map, vector<Room>&rooms);

	// Create the main window
	RenderWindow window(VideoMode(GC::SCREEN_RES.x, GC::SCREEN_RES.y), "DD Combat Prototype");
	window.setFramerateLimit(GC::FRAMERATE_MAX);
	Clock clock;

	//Initialise game objects
	Texture spritesheet;
	spritesheet.create(512, 512);
	spritesheet.loadFromFile("spritesheet.png");
	vector<Tile> tilesVector(23);
	cout << "Tiles vector size: " << tilesVector.size();
	createTileInfo(tilesVector, spritesheet);
	vector<Room> rooms;
	createRooms(rooms);
	Map gameMap;
	createMap(gameMap, rooms);
	Player player1;
	player1.health = GC::PLAYER_HEALTH;
	player1.speed = GC::PLAYER_SPEED;
	player1.spr.setTexture(spritesheet);
	player1.spr.setTextureRect({ 128, 68, 16, 28 });
	player1.spr.setPosition((float)(rooms[0].entrance.x * GC::TILESIZE), (float)(rooms[0].entrance.y * GC::TILESIZE));


	// Start the game loop 
	while (window.isOpen())
	{
		bool fire = false;
		// Process events
		Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::TextEntered)
			{
				if (event.text.unicode == GC::ESCAPE_KEY)
					window.close();
			}
			else if (event.type == Event::KeyReleased)
			{
			}
		}

		// Clear screen
		window.clear();

		float elapsed = clock.getElapsedTime().asSeconds();
		clock.restart();

		// Update the window
		gameMap.Render(window, elapsed, rooms);
		window.display();
	}

	return EXIT_SUCCESS;
}

void createTileInfo(vector<Tile>& tiles, Texture spritesheet)
{
	cout << "Starting tile creation";
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
	tiles[6].r = { 32, 0, 16, 16 };
	tiles[6].spr.setTextureRect(tiles[6].r);

	//"wallHeadTopLeft";
	tiles[7].spr.setTexture(spritesheet);
	tiles[7].r = { 32, 112, 16, 16 };
	tiles[7].spr.setTextureRect(tiles[7].r);

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

	cout << "Ending tile creation";
}

void createRooms(vector<Room>& rooms, vector<Tile>& tiles)
{
	cout << "Starting Room creation";
	for (int i = 0; i < 4; i++)
	{
		rooms.push_back(Room());
		if (i == 0)
			rooms[i].active = true;
		else
			rooms[i].active = false;

		rooms[i].ID = i;
		rooms[i].numEnemies = GC::ENEMY_NUM;
		rooms[i].deadEnemies = 0;
		rooms[i].baseTexture.create(GC::ROOM_SIZE * GC::TILESIZE, GC::ROOM_SIZE * GC::TILESIZE);
		rooms[i].baseTexture.setSmooth(true);

		bool foundEntrance = false;
		bool foundExit = false;
		int tile;
		for (int x = 0; x < GC::ROOM_SIZE; x++)
		{
			for (int y = 0; y < GC::ROOM_SIZE; y++)
			{
				//creates baseTexture
				tile = GameObjects::roomList[i][y][x];
				tiles[tile].spr.setPosition((float)(x * GC::TILESIZE), (float)(y * GC::TILESIZE));
				rooms[i].baseTexture.update(*tiles[tile].spr.getTexture());

				//find entrance and exit
				if (tile == 17 && !foundEntrance)
				{
					foundEntrance = true;
					rooms[i].entrance = { x, y };
				}
				else if (tile == 16 && !foundExit)
				{
					foundExit = true;
					rooms[i].exit = { x, y };
				}
			}
		}
		cout << "Room " << i << " created";
		}
}

void createMap(Map& map, vector<Room>& rooms)
{
	cout << "Starting map creation";
	map.currentRoom = 0;
	map.roomTex.create(GC::ROOM_SIZE * GC::TILESIZE, GC::ROOM_SIZE * GC::TILESIZE);
	map.roomTex.update(rooms[0].baseTexture);
	map.spr.setTexture(map.roomTex);
	for (size_t i = 0; i < GC::ENEMY_NUM; i++)
		map.enemies.push_back(Enemy());

	cout << "Ending map creation";
}