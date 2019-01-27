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


#define CHOPSTICK_SPEED -0.4
#define FORK1_SPEED 0.6
#define FORK2_SPEED -0.8
#define SPOON_SPEED 0.5
#define TOAST1_SPEED 0.9
#define TOAST2_SPEED 1
#define BACON1_SPEED -0.8
#define BACON2_SPEED -0.9
#define TOAST_FINAL_SPEED 0.9

#define TOAST_FINAL_POS_X 500

#define TOAST_FINAL_POS_Y 150
#define CHOPSTICK_POS_Y 500
#define FORK1_POS_Y 450
#define FORK2_POS_Y 600
#define SPOON_POS_Y 550
#define TOAST1_POS_Y 300
#define TOAST2_POS_Y 200
#define BACON1_POS_Y  350
#define BACON2_POS_Y 250


#define TOAST1_SIZE_X 70
#define TOAST2_SIZE_X 70
#define TOAST_FINAL_SIZE_X 300
#define BACON1_SIZE_X 70
#define BACON2_SIZE_X 60

#define TOAST1_SIZE_Y 50
#define TOAST2_SIZE_Y 50
#define TOAST_FINAL_SIZE_Y 35
#define BACON1_SIZE_Y 40
#define BACON2_SIZE_Y 40

class Game
{
public:
	Game();
	~Game();
	void Loop();
	void Move();
	void Draw();
	void GameOver();
	bool isTouched();
	bool isCollision();
	bool moveEgg();
	bool isOnFloor();
	void handleEvent(	sf::Event event);
	void drawContent();
	bool isWon();
	void Win();

private:
	sf::RenderWindow *window;
	sf::Font count_life_font;
	sf::Text count_life;
	sf::SoundBuffer bufferGameOver;
	sf::SoundBuffer bufferLoose;
	sf::SoundBuffer bufferWin;
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
