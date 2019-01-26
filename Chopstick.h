#pragma once
#include <SFML/Graphics.hpp>
#include "Movable.h"

class Chopstick : public Movable
{
public:
	Chopstick(sf::Vector2u size, float posX, float posY, float speed);
	~Chopstick();

	void Move(sf::Vector2u size);

private:
	float originalPosX, originalPosY;
	sf::Texture texture;
};
