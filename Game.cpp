#include "Game.h"

Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(1000, 800), "SFML Starter Template");

	egg = new Egg(window->getSize());

	for(int i=0; i<5; i++)
	{
		Spoon* spoon = new Spoon(window->getSize(), i * 250, 550);
		spoons.push_back(spoon);

	}

	for(int i=0; i<5; i++)
	{
		Chopstick* chopstick = new Chopstick(window->getSize(), i * 250, 600);
		chopsticks.push_back(chopstick);

	}

}


Game::~Game()
{
}

void Game::Loop()
{
	while (window->isOpen())
	{
		// handle events
		sf::Event event;

		while (window->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:

				egg->Move(event);

				break;

			default:
				break;
			}
		}


		for(int i=0; i<5; i++)
		{
			spoons[i]->Move(window->getSize(), 0.2);
			chopsticks[i]->Move(window->getSize(), -0.4);
		}

		for(int i=0; i<5; i++)
		{
			if (egg->GetShape().getGlobalBounds().intersects(spoons[i]->GetShape().getGlobalBounds()))
			{
				window->close();
			}
			if (egg->GetShape().getGlobalBounds().intersects(chopsticks[i]->GetShape().getGlobalBounds()))
			{
				window->close();
			}
		}

		window->clear();

		// draw SFML content
		egg->Draw(*window);
		for(int i=0; i<5; i++)
		{
			spoons[i]->Draw(*window);
			chopsticks[i]->Draw(*window);
		}


		window->display();
	}
}
