#include "Bed.h"
#include <iostream>



Bed::Bed(sf::Vector2u size)
{
	if (!texture.loadFromFile("sprite/bed.png"))
	{
		std::cout<<"Image Bed not found"<<std::endl;
	}
	shape.setTexture(&texture);
	shape.setSize(sf::Vector2f(100, 90));
	shape.setPosition(sf::Vector2f(size.x/2 - shape.getSize().x/2, shape.getSize().y/2 - 20));
}


Bed::~Bed()
{
}
