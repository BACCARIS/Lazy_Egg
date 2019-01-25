#include "Entity.h"



Entity::Entity()
{
}


Entity::~Entity()
{
}

void Entity::Draw(sf::RenderWindow &window)
{
	window.draw(shape);
}

sf::RectangleShape Entity::GetShape()
{
	return shape;
}
