#pragma once

#include <SFML/Graphics.hpp>
#include "Movable.h"

class Fork : public Movable
{
public:
	Fork(sf::Vector2u size, float posX, float posY);
	~Fork();

	void Move(sf::Vector2u size, float speed);

private:
	float originalPosX, originalPosY;
};
