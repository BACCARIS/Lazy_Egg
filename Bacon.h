#pragma once
#include <SFML/Graphics.hpp>
#include "Movable.h"

class Bacon : public Movable
{
public:
	Bacon(sf::Vector2u sizeWindow,  sf::Vector2f size, float posX, float posY, float speed);
	~Bacon();

	void Move(sf::Vector2u size);

private:
	float originalPosX, originalPosY;
	sf::Texture texture;
};
