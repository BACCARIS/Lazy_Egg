#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"

class Life : public Entity
{
public:
	Life(sf::Vector2u size, float x, float y);
	~Life();


private:
	int life_count;

};
