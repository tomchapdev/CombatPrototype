#include <assert.h>
#include <vector>

#include "SFML/Graphics.hpp"
#include "Game.h"

using namespace sf;
using namespace std;

int main()
{
	// Create the main window
	RenderWindow window(VideoMode(GC::SCREEN_RES.x, GC::SCREEN_RES.y), "DD Combat Prototype");
	window.setFramerateLimit(GC::FRAMERATE_MAX);

	//Initialise game objects
	Image spritesImg;
	spritesImg.create(512, 512);
	spritesImg.loadFromFile("spritesheet.png");

	vector<Room> rooms;
	rooms.insert(rooms.begin(), 4, Room());
	DebugPrint("num of rooms " + to_string(rooms.size()));
	for (size_t i = 0; i <= GC::ROOM_NUM - 1; i++)
	{
		rooms[i].Init(spritesImg, i);
	}
	rooms[0].Cleared(spritesImg);

	Map gameMap;
	gameMap.Init(spritesImg, rooms[0].baseTexture);
	gameMap.RoomCleared(rooms[gameMap.currentRoom]);
	Player player1;
	player1.Init(spritesImg);


	Clock clock;
	float elapsed = 0.f;
	int unicode = 0;
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
				unicode = event.text.unicode;
				if (unicode == GC::KEY_ESCAPE)
					window.close();
			}
			else if (event.type == Event::KeyReleased)
			{
			}
		}

		//Handle game objects
		player1.Update();
		player1.CheckMapCollision(gameMap.collisionMap);
		player1.Move(elapsed);
		if (player1.nextRoom)
		{
			player1.nextRoom = false;
			gameMap.currentRoom += 1;
			gameMap.NextRoom(rooms[gameMap.currentRoom], player1);
		}
		gameMap.UpdateEnemies(player1, elapsed);

		// Clear screen
		window.clear();

		elapsed = clock.getElapsedTime().asSeconds();
		clock.restart();

		// Update the window
		gameMap.Render(window);
		player1.Render(window);
		rooms[gameMap.currentRoom].RenderDoorTops(window, spritesImg);
		window.display();
	}

	return EXIT_SUCCESS;
}