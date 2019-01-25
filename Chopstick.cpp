#include "Chopstick.h"
#include <iostream>



Chopstick::Chopstick(sf::Vector2u size, float posX, float posY)
{
	if (!texture.loadFromFile("sprite/chopsticks.png"))
	{
		std::cout<<"Image Chopstick not found"<<std::endl;
	}
	shape.setTexture(&texture);
	shape.setSize(sf::Vector2f(70, 30));
	shape.setPosition(sf::Vector2f(posX, posY));

	originalPosX = posX;
	originalPosY = posY;

}


Chopstick::~Chopstick()
{
}


void Chopstick::Move(sf::Vector2u size, float speed)
{
	shape.move(speed, 0);

	if (shape.getPosition().x < 0)
	{
		shape.setPosition(sf::Vector2f(size.x - shape.getSize().x, originalPosY));
	}
}
