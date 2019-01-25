#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"

class Spoon : public Entity
{
public:
	Spoon(sf::Vector2u size, float posX, float posY);
	~Spoon();

	void Move(sf::Vector2u size, float speed);

private:
	float originalPosX, originalPosY;
	sf::Texture texture;
};
