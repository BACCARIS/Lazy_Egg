#pragma once

#include <SFML/Graphics.hpp>
#include "Movable.h"

class Spoon : public Movable
{
public:
	Spoon(sf::Vector2u size, float posX, float posY);
	~Spoon();

	void Move(sf::Vector2u size, float speed);

private:
	float originalPosX, originalPosY;
};
