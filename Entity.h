#pragma once

#include <SFML/Graphics.hpp>

class Entity
{
public:
	Entity();
	~Entity();

	void Draw(sf::RenderWindow &window);
	sf::RectangleShape GetShape();

protected:
	sf::RectangleShape shape;

};
