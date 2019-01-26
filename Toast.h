#pragma once
#include <SFML/Graphics.hpp>
#include "Movable.h"


class Toast : public Movable
{
public:
	Toast(sf::Vector2u sizeWindow, sf::Vector2f size, float posX, float posY, float speed);
	~Toast();

	void Move(sf::Vector2u size);

private:
	float originalPosX, originalPosY;
	sf::Texture texture;
};
