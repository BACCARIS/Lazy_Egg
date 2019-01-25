#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Chopstick : public Entity
{
public:
	Chopstick(sf::Vector2u size, float posX, float posY);
	~Chopstick();

	void Move(sf::Vector2u size, float speed);

private:
	float originalPosX, originalPosY;
	sf::Texture texture;
};
