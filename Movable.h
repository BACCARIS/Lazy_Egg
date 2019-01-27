#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"

class Movable : public Entity
{
public:
	Movable();
	~Movable();
	float getSpeed();
	void setSpeed(float x);
	virtual void Move(sf::Vector2u size, float speed) {};

protected :
	float speed;
};
