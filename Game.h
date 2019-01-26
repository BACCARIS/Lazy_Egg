#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <chrono>
#include <thread>
#include "Egg.h"
#include "Spoon.h"
#include "Chopstick.h"
#include "Fork.h"
#include "Bacon.h"
#include "Toast.h"
#include "Bed.h"
#include "Life.h"

class Game
{
public:
	Game();
	~Game();
	void Loop();
	void Move();
	void Draw();
	void Lose();
	bool isTouched();
	void handleEvent(	sf::Event event);

private:
	sf::RenderWindow *window;
	sf::Font count_life_font;
	sf::Text count_life;
	sf::SoundBuffer buffer;
	Egg *egg;
	Bed *bed;
	std::vector<Spoon*> spoons;
	std::vector<Chopstick*> chopsticks;
	std::vector<Fork*> forks;
	std::vector<Fork*> forks2;
	std::vector<Bacon*> bacons;
	std::vector<Toast*> toasts;
	Toast* toastFinal; //toast final

	std::vector<Bacon*> bacons2;
	std::vector<Toast*> toasts2;

	sf::RectangleShape* start;
	std::vector<Life*> lives;

};
