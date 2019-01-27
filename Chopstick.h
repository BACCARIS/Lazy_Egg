#pragma once
#include <SFML/Graphics.hpp>
#include "Movable.h"

class Chopstick : public Movable
{
public:
	Chopstick(sf::Vector2u size, float posX, float posY);
	~Chopstick();

	void Move(sf::Vector2u size, float speed);

private:
	float originalPosX, originalPosY;
};
