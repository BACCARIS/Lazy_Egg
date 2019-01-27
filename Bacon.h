#pragma once
#include <SFML/Graphics.hpp>
#include "Movable.h"

class Bacon : public Movable
{
public:
	Bacon(sf::Vector2u sizeWindow,  sf::Vector2f size, float posX, float posY);
	~Bacon();

	void Move(sf::Vector2u size, float speed);

private:
	float originalPosX, originalPosY;
	sf::Texture texture;
};
