#pragma once

#include <SFML/Graphics.hpp>
#include "Movable.h"

class Fork : public Movable
{
public:
	Fork(sf::Vector2u size, float posX, float posY, float speed);
	~Fork();

	void Move(sf::Vector2u size);

private:
	float originalPosX, originalPosY;
	sf::Texture texture;
};
