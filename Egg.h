#pragma once

#include <SFML/Graphics.hpp>
#include "Movable.h"

class Egg : public Movable
{
public:
	Egg(sf::Vector2u size);
	~Egg();
	void Move(sf::Event event, sf::Vector2u size);
	void Move(sf::Vector2u size, float speed);
	int getLife(){ return life; };
	void setLife(int x){ life = x; };


private:
	sf::Texture texture;
	int life;
};
