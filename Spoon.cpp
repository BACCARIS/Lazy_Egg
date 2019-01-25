#include "Spoon.h"
#include <iostream>



Spoon::Spoon(sf::Vector2u size, float posX, float posY)
{
	if (!texture.loadFromFile("sprite/spoon.png"))
	{
		std::cout<<"Image Spoon not found"<<std::endl;
	}
	shape.setTexture(&texture);
	shape.scale(sf::Vector2f(-1, 1));
	shape.setSize(sf::Vector2f(70, 30));
	shape.setPosition(sf::Vector2f(posX, posY));

	originalPosX = posX;
	originalPosY = posY;

}


Spoon::~Spoon()
{
}


void Spoon::Move(sf::Vector2u size, float speed)
{
	shape.move(speed, 0);

	if (shape.getPosition().x > size.x)
	{
		shape.setPosition(sf::Vector2f(0 - shape.getSize().x, originalPosY));
	}
}
