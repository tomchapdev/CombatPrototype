#pragma once
#include <assert.h>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Game.h"


//void Player::Movement()

//void Player::Attack()

//void Enemy::Movement(

//void Enemy::Attack()


//void Room::Enter()

//void Room::Clear(Map map)


//void Map::NextRoom(std::vector<Room> rooms)

void Map::Render(sf::RenderWindow& window, float elapsed, std::vector<Room> rooms)
{
	
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