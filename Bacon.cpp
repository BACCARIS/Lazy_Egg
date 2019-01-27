#include "Bacon.h"
#include <iostream>



Bacon::Bacon(sf::Vector2u sizeWindow,  sf::Vector2f size,float posX, float posY)
{
	if (!texture.loadFromFile("sprite/bacon.png"))
	{
		std::cout<<"Image Bacon not found"<<std::endl;
	}
	shape.setTexture(&texture);
	shape.setSize(size);
	shape.setPosition(sf::Vector2f(posX, posY));

	originalPosX = posX;
	originalPosY = posY;
	this->speed = 0;
}


Bacon::~Bacon()
{
}


void Bacon::Move(sf::Vector2u sizeWindow, float speed)
{
	this->speed = speed;
	shape.move(speed, 0);

	if(speed>0 && shape.getPosition().x > sizeWindow.x)
	{
		shape.setPosition(sf::Vector2f(0 - shape.getSize().x, originalPosY));
	}

	if(speed<0 && shape.getPosition().x < 0)
	{
		shape.setPosition(sf::Vector2f(sizeWindow.x - shape.getSize().x/2, originalPosY));
	}
}
