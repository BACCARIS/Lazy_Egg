#include <iostream>
#include "Entity.h"
#include "Life.h"



Life::Life(sf::Vector2u size, float x, float y)
{
	if (!texture.loadFromFile("sprite/heart.png"))
	{
    std::cout<<"Image heart not found"<<std::endl;
	}
	shape.setTexture(&texture);
	shape.setSize(sf::Vector2f(20, 20));
	//shape.setScale(1.0f, 0.4f);
	shape.setPosition(sf::Vector2f(x, y));
}


Life::~Life()
{
}

