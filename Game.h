#pragma once

#include <SFML/Graphics.hpp>
#include "Egg.h"
#include "Spoon.h"
#include "Chopstick.h"

class Game
{
public:
	Game();
	~Game();

	void Loop();

private:
	sf::RenderWindow *window;
	Egg *egg;
	std::vector<Spoon*> spoons;
	std::vector<Chopstick*> chopsticks;

};
