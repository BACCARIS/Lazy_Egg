#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"


class Bed : public Entity
{
public:
	Bed(sf::Vector2u size);
	~Bed();

	void Move(sf::Vector2u size);

private:
	sf::Texture texture;
};
