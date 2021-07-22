#pragma once
#include <assert.h>
#include <string>
#include <math.h>
#include "SFML/Graphics.hpp"
#include "Game.h"

void Player::Init(sf::Image spritesheet)
{
	//player data
	health = GC::PLAYER_HEALTH;
	speed = GC::PLAYER_SPEED;
	tex.loadFromImage(spritesheet, {128, 68, 144, 28});
	sprite.setTexture(tex);
	sprite.setTextureRect({ 0, 0, 16, 28});
	sprite.setScale(GC::SPRITE_SCALE, GC::SPRITE_SCALE);
	sprite.setPosition((float)(GC::SCREEN_RES.x / 2), (float)(GC::SCREEN_RES.y / 2));

	//sword data
	swTex.loadFromImage(spritesheet, { 339, 26, 10, 21 });
	swSprite.setTexture(swTex);
	swSprite.setOrigin(0, 21);
	swSprite.setScale(GC::SPRITE_SCALE, GC::SPRITE_SCALE);
}

void Player::Update()
{
	//get movement booleans
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		movingLeft = true;
	}
	else
	{
		movingLeft = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		movingRight = true;
	}
	else
	{
		movingRight = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		movingUp = true;
	}
	else
	{
		movingUp = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		movingDown = true;
	}
	else
	{
		movingDown = false;
	}

	//Extra code for you to check out, I couldn't get it working, needed more time
	/*
	if (!attacking)
	{
		//get aim rotation
		sf::Vector2i mPos = mouse.getPosition();
		sf::Vector2f sprPos = sprite.getPosition();
		sf::Vector2f pos;
		bool left, up;

		pos.x = sprPos.x - (float)mPos.x;
		pos.y = sprPos.x - (float)mPos.x;
		if (pos.x < 0)
			left = true;
		else
			left = false;
		if (pos.y < 0)
			up = true;
		else
			up = false;
		//tan(opposite / adjacent) going clockwise for ease
		if (up && !left)
		{
			aimRotation = std::tan(std::abs(pos.x) / std::abs(pos.y) * 180.f / GC::PI);
		}
		else if (!left && !up)
		{
			aimRotation = std::tan(std::abs(pos.y) / std::abs(pos.x) * 180.f / GC::PI) + 90.f;
		}
		else if (!up && left)
		{
			aimRotation = std::tan(std::abs(pos.x) / std::abs(pos.y) * 180.f / GC::PI) + 180.f;
		}
		else //left && up
		{
			aimRotation = std::tan(std::abs(pos.y) / std::abs(pos.x) * 180.f / GC::PI) + 270.f;
		}

		swRotation = aimRotation;
		swSprite.setRotation(aimRotation);

		//get position
		float triAngle;
		sf::Vector2f swDist = { 0.f, 0.f };

		//going clockwise for ease
		if (up && !left)
		{
			//degrees < 90
			triAngle = aimRotation;
			//adjacent
			swDist.y -= std::cosf(triAngle) * GC::SWORD_HOVER;
			//opposite
			swDist.x += std::sinf(triAngle) * GC::SWORD_HOVER;
		}
		else if (!left && !up)
		{
			//degrees < 90
			triAngle = aimRotation - 90.f;
			//adjacent
			swDist.y += std::cosf(triAngle) * GC::SWORD_HOVER;
			//opposite
			swDist.x += std::sinf(triAngle) * GC::SWORD_HOVER;
		}
		else if (!up && left)
		{
			//degrees < 90
			triAngle = aimRotation - 180.f;
			//adjacent
			swDist.y += std::cosf(triAngle) * GC::SWORD_HOVER;
			//opposite
			swDist.x -= std::sinf(triAngle) * GC::SWORD_HOVER;
		}
		else //left && up
		{
			//degrees < 90
			triAngle = aimRotation - 270.f;
			//adjacent
			swDist.x -= std::cosf(triAngle) * GC::SWORD_HOVER;
			//opposite
			swDist.y -= std::sinf(triAngle) * GC::SWORD_HOVER;
		}

		//initiate attack
		if (mouse.isButtonPressed(sf::Mouse::Left))
		{
			attacking = true;
			attack.start = aimRotation + (GC::ATTACK_SWEEP / 2.f);
			attack.end = aimRotation - (GC::ATTACK_SWEEP / 2.f);
				
			//maintain 360 degrees
			if (attack.start > 360.f)
				attack.start -= 360.f;
			if (attack.end < 0.f)
				attack.end += 360.f;

			swRotation = attack.start;
		}
		swSprite.setPosition(sprPos.x + (float)(GC::SCALED_TILE / 2) + swDist.x, sprPos.y + (float)(12 * GC::SPRITE_SCALE) + (float)(GC::SCALED_TILE / 2) + swDist.y);
	}*/

	
}

void Player::CheckMapCollision(const int collisionMap[GC::TILESIZE][GC::TILESIZE])
{
	int mapTileNext, mapTileOn;
	const int tileSize = GC::TILESIZE * (int)GC::SPRITE_SCALE;
	sf::Vector2f pos;
	sf::Vector2i tilePos;
	pos = sprite.getPosition();
	pos.y += sprite.getGlobalBounds().height;
	tilePos.x = (int)(floorf(pos.x)) / tileSize;
	tilePos.y = (int)(floorf(pos.y)) / tileSize;
	if (movingUp)
	{
		//check left of sprite
		mapTileNext = collisionMap[tilePos.x][tilePos.y - 1];
		if (mapTileNext == 1)
		{
			if (pos.y < (tilePos.y * tileSize) + GC::WALL_WIDTH)
				movingUp = false;
		}
		//check if leaving room
		if (mapTileNext == 4)
		{
			if (pos.y < (tilePos.y * tileSize) + GC::WALL_WIDTH)
				nextRoom = true;
		}
		//check right of sprite
		mapTileNext = collisionMap[tilePos.x + 1][tilePos.y - 1];
		if (mapTileNext == 1)
		{
			if (pos.y < (tilePos.y * tileSize) + GC::WALL_WIDTH)
				movingUp = false;
		}
	}
	if (movingDown)
	{
		//check left of sprite
		mapTileNext = collisionMap[tilePos.x][tilePos.y + 1];
		if (mapTileNext == 1)
		{
			if (pos.y > ((tilePos.y + 1) * tileSize) - (GC::WALL_WIDTH * GC::SPRITE_SCALE))
				movingDown = false;
		}
		if (mapTileNext == 4)
		{
			if (pos.y > ((tilePos.y + 1) * tileSize) - (GC::WALL_WIDTH * GC::SPRITE_SCALE))
				nextRoom = true;
		}
		//check right of sprite
		mapTileNext = collisionMap[tilePos.x + 1][tilePos.y + 1];
		if (mapTileNext == 1)
		{
			if (pos.y > ((tilePos.y + 1) * tileSize) - (GC::WALL_WIDTH * GC::SPRITE_SCALE))
				movingDown = false;
		}
	}
	if (movingLeft)
	{
		mapTileNext = collisionMap[tilePos.x - 1][tilePos.y];
		mapTileOn = collisionMap[tilePos.x][tilePos.y];
		//check tile moving to
		if (mapTileNext == 1)
		{
			if (pos.x < (tilePos.x * tileSize) + (GC::WALL_WIDTH * GC::SPRITE_SCALE))
				movingLeft = false;
		}
		//check tile standing on
		else if (mapTileOn == 2)
		{
			if (pos.x < ((tilePos.x) * tileSize) + (GC::WALL_WIDTH * GC::SPRITE_SCALE))
				movingLeft = false;
		}
	}
	if (movingRight)
	{
		//get the right side of sprite
		tilePos.x += 1;
		pos.x += tileSize;
		mapTileNext = collisionMap[tilePos.x + 1][tilePos.y];
		mapTileOn = collisionMap[tilePos.x][tilePos.y];
		//check tile moving to
		if (mapTileNext == 1)
		{
			if (pos.x > ((tilePos.x + 1) * tileSize) - (GC::WALL_WIDTH * GC::SPRITE_SCALE))
				movingRight = false;
		}
		//check tile standing on
		else if (mapTileOn == 3 || mapTileOn == 1)
		{
			if (pos.x > ((tilePos.x + 1) * tileSize) - (GC::WALL_WIDTH * GC::SPRITE_SCALE))
				movingRight = false;
		}
	}
		
}

void Player::Move(float elapsed)
{
	sf::Vector2f pos;
	pos = sprite.getPosition();

	if (movingUp)
		pos.y -= speed * elapsed;
	if (movingDown)
		pos.y += speed * elapsed;
	if (movingLeft)
		pos.x -= speed * elapsed;
	if (movingRight)
		pos.x += speed * elapsed;

	sprite.setPosition(pos);
}

void Player::Attack()
{

}

void Player::Render(sf::RenderWindow& window)
{
	//sword above player
	if (swRotation < 90.f || swRotation > 270.f)
	{
		window.draw(swSprite);
		window.draw(sprite);
	}
	else //sword below player
	{
		window.draw(sprite);
		window.draw(swSprite);
	}
}

void Enemy::Init(sf::Image spritesheet)
{
	tex.create(GC::TILESIZE * 8, GC::TILESIZE);
	tex.loadFromImage(spritesheet, GC::ENEMY_TILES1);
	spr.setTexture(tex);
	spr.setTextureRect({ 0, 0, GC::TILESIZE, GC::TILESIZE });
	spr.setScale(GC::SPRITE_SCALE, GC::SPRITE_SCALE);
}

void Enemy::Movement(Player player, float elapsed)
{
	sf::Vector2f ePos = spr.getPosition();
	sf::Vector2f pPos = player.sprite.getPosition();
	sf::Vector2f diff = pPos - ePos;

	if (diff.x < 0)
		ePos.x -= speed * elapsed;
	else
		ePos.x = speed * elapsed;

	if (diff.y < 0)
		ePos.y -= speed * elapsed;
	else
		ePos.y = speed * elapsed;

	spr.setPosition(ePos);
	
	diff = pPos - ePos;
	if (diff.x < GC::SCALED_TILE && diff.x > -GC::SCALED_TILE)
	{
		if (diff.y < GC::SCALED_TILE && diff.y > -GC::SCALED_TILE)
			attack = true;
	}
}

void Enemy::Attack(Player& player)
{
	attack = false;
	player.health -= 1;
	knockback = true;

	sf::Vector2f ePos = spr.getPosition();
	sf::Vector2f pPos = player.sprite.getPosition();
	sf::Vector2f diff = pPos - ePos;

	if (diff.x < 0)
		knock[0] -= GC::ENEMY_KNOCKBACK;
	else
		knock[0] += GC::ENEMY_KNOCKBACK;

	if (diff.y < 0)
		knock[1] -= GC::ENEMY_KNOCKBACK;
	else
		knock[1] += GC::ENEMY_KNOCKBACK;
	
}

void Enemy::Knockback(float elapsed)
{
	sf::Vector2f pos = spr.getPosition();
	float dist = GC::ENEMY_KNOCKBACK * GC::SPRITE_SCALE * elapsed;
	knock[2] += dist;

	dist = knock[0] * GC::SPRITE_SCALE * elapsed;
	pos.x += dist;
	dist = knock[1] * GC::SPRITE_SCALE * elapsed;
	pos.y += dist;

	spr.setPosition(pos);
	if (knock[2] > GC::ENEMY_KNOCKBACK)
		knockback = false;
}

void Enemy::Render(sf::RenderWindow& window)
{
	window.draw(spr);
}

void Room::Init(sf::Image spritesheet, int id)
{
	DebugPrint("Starting Room creation");
	cleared = false;
	ID = id;
	numEnemies = GC::ENEMY_NUM;
	deadEnemies = 0;
	spawners.insert(spawners.begin(), GC::ENEMY_NUM, Dim2Di());
	int spawnerCounter = 0;

	baseTexture.create(GC::ROOM_SIZE * GC::TILESIZE, GC::ROOM_SIZE * GC::TILESIZE);
	sf::Texture tileTex1by1;
	sf::Texture tileTex2by1;
	sf::Texture tileTexWall;
	sf::Texture tileTexWallHead;
	tileTex1by1.create(GC::TILESIZE, GC::TILESIZE);
	tileTex2by1.create(GC::TILESIZE * 2, GC::TILESIZE);
	tileTexWall.create(GC::WALL_WIDTH, GC::TILESIZE);
	tileTexWallHead.create(GC::TILESIZE, GC::WALL_HEAD);


	int tile, tx, ty, wallPos;
	for (int y = 0; y < GC::ROOM_SIZE; ++y)
	{
		for (int x = 0; x < GC::ROOM_SIZE; ++x)
		{
			//creates baseTexture
			tile = GC::roomList[id][y][x];
			if (tile > -1)
			{
				tx = x * GC::TILESIZE;
				//entrance and exit door bottoms
				if (tile == 14 || tile == 16)
				{
					if (tile == 16)
						exit = { x, y };
					else
						entrance = { x, y };

					ty = y * GC::TILESIZE;
					tileTex2by1.loadFromImage(spritesheet, GC::tileList[tile]);
					baseTexture.update(tileTex2by1, tx, ty);
					++x;
				}
				else if (tile == 11 || tile == 12 || tile == 23 || tile == 24)
				{
					if (tile == 11 || tile == 24)
					{
						wallPos = 0;
					}
					else
					{
						wallPos = 11;
					}
						
					ty = y * GC::TILESIZE;
					tileTex1by1.loadFromImage(spritesheet, GC::tileList[0]);
					tileTexWall.loadFromImage(spritesheet, GC::tileList[tile]);
					baseTexture.update(tileTex1by1, tx, ty);
					tx += wallPos;
					baseTexture.update(tileTexWall, tx, ty);
				}
				else if (tile > 5 && tile < 9) 
				{
					if (tile == 6 || tile == 7 || tile == 8)
					{
						wallPos = 12;
					}
					else
					{
						wallPos = 0;
					}

					ty = y * GC::TILESIZE;
					if (y != 0 && GC::roomList[id][y - 1][x] == 0)
					{
						tileTex1by1.loadFromImage(spritesheet, GC::tileList[0]);
						baseTexture.update(tileTex1by1, tx, ty);
					}
					tileTexWallHead.loadFromImage(spritesheet, GC::tileList[tile]);
					ty += wallPos;
					baseTexture.update(tileTexWallHead, tx, ty);
				}
				else if (tile == 4 || tile == 5)
				{
					if (tile == 4)
						tileTexWallHead.loadFromImage(spritesheet, GC::tileList[20]);
					else
						tileTexWallHead.loadFromImage(spritesheet, GC::tileList[21]);
					ty = y * GC::TILESIZE;
					tileTex1by1.loadFromImage(spritesheet, GC::tileList[tile]);
					baseTexture.update(tileTex1by1, tx, ty);
					wallPos = -4;
					ty += wallPos;
					baseTexture.update(tileTexWallHead, tx, ty);
				}
				else if (tile == 22)
				{
					ty = y * GC::TILESIZE;
					spawners[spawnerCounter] = { x, y };
					spawnerCounter += 1;
					tileTex1by1.loadFromImage(spritesheet, GC::tileList[tile]);
					baseTexture.update(tileTex1by1, tx, ty);
				}
				//dont draw the door tops
				else if (tile != 13 && tile != 15)
				{
					ty = y * GC::TILESIZE;
					tileTex1by1.loadFromImage(spritesheet, GC::tileList[tile]);
					baseTexture.update(tileTex1by1, tx, ty);
				}
			}
		}
	}
	DebugPrint("Room created" + std::to_string(id));
}

void Room::Cleared(sf::Image spritesheet)
{
	cleared = true;
	sf::Texture tileTex2by1;
	tileTex2by1.create(GC::TILESIZE * 2, GC::TILESIZE);
	tileTex2by1.loadFromImage(spritesheet, GC::tileList[14]);
	tileTex2by1.setSmooth(true);
	baseTexture.update(tileTex2by1, exit.x * GC::TILESIZE, exit.y * GC::TILESIZE);
}

void Room::RenderDoorTops(sf::RenderWindow& window, sf::Image spritesheet)
{
	sf::Texture tileTex2by1;
	tileTex2by1.create(GC::TILESIZE * 2, GC::TILESIZE);
	sf::Sprite doorTop;
	doorTop.setScale(GC::SPRITE_SCALE, GC::SPRITE_SCALE);
	int ex = 15;
	int ent = 13;

	if (ID != 0)
	{
		//entrance
		tileTex2by1.loadFromImage(spritesheet, GC::tileList[ent]);
		doorTop.setTexture(tileTex2by1);
		doorTop.setPosition((float)(entrance.x * GC::SCALED_TILE), (float)((entrance.y - 1) * GC::SCALED_TILE));
		window.draw(doorTop);
	}

	//exit
	if (cleared)
	{
		tileTex2by1.loadFromImage(spritesheet, GC::tileList[ent]);
	}
	else
	{
		tileTex2by1.loadFromImage(spritesheet, GC::tileList[ex]);
	}
	doorTop.setTexture(tileTex2by1);
	doorTop.setPosition((float)(exit.x * GC::SCALED_TILE), (float)((exit.y - 1) * GC::SCALED_TILE));
	window.draw(doorTop);
}

void Map::Init(sf::Image spritesheet, sf::Texture rTex)
{
	DebugPrint("Starting map creation");
	currentRoom = 0;
	roomTex.create(GC::ROOM_SIZE * GC::TILESIZE, GC::ROOM_SIZE * GC::TILESIZE);
	roomTex.update(rTex);
	spr.setScale(GC::SPRITE_SCALE, GC::SPRITE_SCALE);
	spr.setTexture(rTex);

	GetCollisionMap();

	enemies.insert(enemies.begin(), GC::ENEMY_NUM, Enemy());
	sf::Texture enemyTex;
	enemyTex.create(GC::TILESIZE, GC::TILESIZE);
	enemyTex.loadFromImage(spritesheet, GC::ENEMY_TILES1);

	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i].Init(spritesheet);
	}
	DebugPrint("Ending map creation");
}

void Map::GetCollisionMap()
{
	if (currentRoom > 0)
	{
		for (int y = 0; y < GC::ROOM_SIZE; ++y)
		{
			for (int x = 0; x < GC::ROOM_SIZE; ++x)
			{
				collisionMap[x][y] = 0;
			}
		}
	}

	int tile;
	for (int y = 0; y < GC::ROOM_SIZE; ++y)
	{
		for (int x = 0; x < GC::ROOM_SIZE; ++x)
		{
			//creates baseTexture
			tile = GC::roomList[currentRoom][y][x];
			//top/bottom walls
			if (tile > 0 && tile < 6)
			{
				collisionMap[x][y] = 1;
			}
			else if (tile > 12 && tile < 20)
			{
				//doors
				if (tile == 16 || tile == 14)
					collisionMap[x + 1][y] = 1;
				//ignore tops
				else if (tile != 13 && tile != 15)
					collisionMap[x][y] = 1;
			}
			//left walls
			else if (tile == 11 || tile == 24)
			{
				collisionMap[x][y] = 2;
				if (x != 0)
					collisionMap[x - 1][y] = 1;
			}
			//right walls
			else if (tile == 12 || tile == 23)
			{
				collisionMap[x][y] = 3;
				if (x != 15)
					collisionMap[x + 1][y] = 1;
			}
		}
	}
}

void Map::SpawnEnemies(Room room)
{
	float x, y;
	for (int i = 0; i < room.numEnemies; i++)
	{
		enemies[i].alive = true;
		enemies[i].health = GC::ENEMY_HEALTH;
		enemies[i].speed = GC::ENEMY_SPEED;
		x = room.spawners[i].x * GC::TILESIZE * GC::SPRITE_SCALE;
		y = room.spawners[i].y * GC::TILESIZE * GC::SPRITE_SCALE;
		enemies[i].spr.setPosition(x, y);
	}
}

void Map::RoomCleared(Room room)
{
	//update renderer
	roomTex.update(room.baseTexture);
	spr.setTexture(roomTex);
	//allow player to proceed
	collisionMap[room.exit.x][room.exit.y] = 4;
	collisionMap[room.exit.x + 1][room.exit.y] = 4;
}

void Map::NextRoom(Room room, Player& player)
{
	roomTex.update(room.baseTexture);
	spr.setTexture(roomTex);
	GetCollisionMap();
	SpawnEnemies(room);
	player.sprite.setPosition((float)(room.entrance.x * GC::TILESIZE * GC::SPRITE_SCALE) + (GC::TILESIZE / 2), (float)(room.entrance.y * GC::TILESIZE * GC::SPRITE_SCALE));
}

void Map::UpdateEnemies(Player& player, float elapsed)
{
	for (size_t i = 0; i < enemies.size(); i++)
	{
		if (enemies[i].alive)
		{
			if (enemies[i].knockback)
				enemies[i].Knockback(elapsed);
			else
				enemies[i].Movement(player, elapsed);
			
			if (enemies[i].attack)
				enemies[i].Attack(player);
		}
	}
}

void Map::Render(sf::RenderWindow& window)
{
	window.draw(spr);
	for (int i = 0; i < enemies.size(); i++)
	{
		if (enemies[i].alive)
			enemies[i].Render(window);
	}
}

bool LoadTexture(const std::string& file, sf::Texture& tex)
{
	if (tex.loadFromFile(file))
	{
		tex.setSmooth(true);
		return true;
	}
	assert(false);
	return false;
}

void DebugPrint(const std::string& mssg1, const std::string& mssg2)
{
	OutputDebugString(mssg1.c_str());
	OutputDebugString("\n");
	if (!mssg2.empty()) {
		OutputDebugString(mssg2.c_str());
		OutputDebugString("\n");
	}
}