#pragma once
#include <SFML/Graphics.hpp>
#include "Movable.h"


class Toast : public Movable
{
public:
	Toast(sf::Vector2u sizeWindow, sf::Vector2f size, float posX, float posY);
	~Toast();

	void Move(sf::Vector2u size, float speed);

private:
	float originalPosX, originalPosY;
};
