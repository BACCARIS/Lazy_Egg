#pragma once

#include <SFML/Graphics.hpp>

class Entity
{
public:
	Entity();
	virtual ~Entity();

	void Draw(sf::RenderWindow &window);
	sf::RectangleShape GetShape();


protected:
	sf::RectangleShape shape;
    sf::Texture texture;
};
