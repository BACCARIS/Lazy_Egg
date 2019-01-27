#include "Chopstick.h"
#include <iostream>



Chopstick::Chopstick(sf::Vector2u size, float posX, float posY)
{
	if (!texture.loadFromFile("sprite/chopsticks.png"))
	{
		std::cout<<"Image Chopstick not found"<<std::endl;
	}
	shape.setTexture(&texture);
	shape.setSize(sf::Vector2f(50, 60));
	shape.setPosition(sf::Vector2f(posX, posY));

	originalPosX = posX;
	originalPosY = posY;
	this->speed = 0;
}


Chopstick::~Chopstick()
{
}


void Chopstick::Move(sf::Vector2u size, float speed)
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
