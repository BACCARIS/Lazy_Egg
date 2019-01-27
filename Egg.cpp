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
	shape.setSize(sf::Vector2f(50, 80));
	shape.setScale(1.0f, 0.4f);
	shape.setPosition(sf::Vector2f(size.x/2, size.y - shape.getSize().y + 30));
	life = 5000;
}


Egg::~Egg()
{
}

void Egg::setPosition(sf::Vector2f position)
{
	shape.setPosition(position);
}

void Egg::Move(sf::Vector2u size, float speed)
{
	this->speed = speed;
	  if(shape.getPosition().x > 0 && shape.getPosition().x < size.x) shape.move(speed, 0);

}


void Egg::Move(sf::Event event, sf::Vector2u size)
{
	if (sf::Keyboard::Left == event.key.code)
	{
        if(shape.getPosition().x > 0) shape.move(-40, 0);
	}
	else if (sf::Keyboard::Right == event.key.code)
	{
        if(shape.getPosition().x < size.x) shape.move(40, 0);
	}
	else if (sf::Keyboard::Up == event.key.code)
	{
        if(shape.getPosition().y > 0) shape.move(0, -50);
	}
	else if (sf::Keyboard::Down == event.key.code)
	{
        if(shape.getPosition().y < size.y) shape.move(0, 50);
	}
	else if (sf::Keyboard::Space == event.key.code)
	{
				if(shape.getPosition().y > 0) shape.move(0, -50);
	}
}
