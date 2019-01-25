#include <iostream>
#include "Entity.h"
#include "Egg.h"



Egg::Egg(sf::Vector2u size)
{

	if (!texture.loadFromFile("sprite/gudetama.png"))
	{
    std::cout<<"Image Lazy_egg not found"<<std::endl;
	}
	shape.setTexture(&texture);
	shape.setSize(sf::Vector2f(70, 70));
	shape.setScale(1.0f, 0.4f);
	shape.setPosition(sf::Vector2f(shape.getPosition().x, size.y - shape.getSize().y));
}


Egg::~Egg()
{
}


void Egg::Move(sf::Event event)
{
	if (sf::Keyboard::Left == event.key.code)
	{
        shape.move(-40, 0);
	}
	else if (sf::Keyboard::Right == event.key.code)
	{
        shape.move(40, 0);
	}
	else if (sf::Keyboard::Up == event.key.code)
	{
        shape.move(0, -40);
	}
	else if (sf::Keyboard::Down == event.key.code)
	{
        shape.move(0, 40);
	}
}
