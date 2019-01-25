#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"

class Egg : public Entity
{
public:
	Egg(sf::Vector2u size);
	~Egg();
	void Move(sf::Event event);


private:
	//sf::RectangleShape frog;
	sf::Texture texture;

};
