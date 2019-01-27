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
	shape.setSize(sf::Vector2f(60, 40));
	shape.setPosition(sf::Vector2f(posX, posY));

	originalPosX = posX;
	originalPosY = posY;
	this->speed = 0;
}


Spoon::~Spoon()
{
}


void Spoon::Move(sf::Vector2u size, float speed)
{
	this->speed = speed;
	shape.move(speed, 0);

	if(speed>0 && shape.getPosition().x > size.x)
	{
		shape.setPosition(sf::Vector2f(0 - shape.getSize().x, originalPosY));
	}

	if(speed<0 && shape.getPosition().x < 0)
	{
		shape.setPosition(sf::Vector2f(size.x - shape.getSize().x/2, originalPosY));
	}
}
