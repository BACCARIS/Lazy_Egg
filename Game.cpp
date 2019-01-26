#include <iostream>
#include "Game.h"

Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(1000, 700), "Lazy Egg");

	egg = new Egg(window->getSize());
	bed = new Bed(window->getSize());
	toastFinal = new Toast(window->getSize(), sf::Vector2f(70, 50), 250, 150, 0.9);

	for(int i=0; i<4; i++)
	{
		Spoon* spoon = new Spoon(window->getSize(), i * 250, 550, 0.5);
		spoons.push_back(spoon);
		Chopstick* chopstick = new Chopstick(window->getSize(), i * 250, 500, -0.4);
		chopsticks.push_back(chopstick);

		Fork* fork = new Fork(window->getSize(), i * 250, 450, 0.6);
		forks.push_back(fork);
		fork = new Fork(window->getSize(), i * 250, 600, -0.2);
		forks2.push_back(fork);

		Toast* toast = new Toast(window->getSize(), sf::Vector2f(70, 50), i * 250, 300, 0.9);
		toasts.push_back(toast);

		Bacon* bacon = new Bacon(window->getSize(),  sf::Vector2f(70, 40), i * 250, 350, -0.8);
		bacons.push_back(bacon);

		toast = new Toast(window->getSize(), sf::Vector2f(70, 50), i * 250, 200, 0.6);
		toasts2.push_back(toast);

		bacon = new Bacon(window->getSize(), sf::Vector2f(50, 40),  i * 250, 250, -0.9);
		bacons2.push_back(bacon);
	}


	for(int i=0; i< (int)egg->getLife()/1000+1; i++)
	{
		Life* life = new Life(window->getSize(), 60 + i*10, 0);
		lives.push_back(life);
	}

	// set text font
	if(!count_life_font.loadFromFile("fonts/ARCADECLASSIC.TTF")){
		std::cout<<"font ARCADECLASSIC not found"<<std::endl;
	}

	// set sound buffer
		if (!buffer.loadFromFile("sounds/game_over.wav")){
		std::cout<<"sound game_over not found"<<std::endl;
	}
}


Game::~Game()
{
}

void Game::Loop()
{
	bool touched = false;

	while (window->isOpen())
	{
		// Decide win or loose
		if( !egg->getLife() ){

			Lose();
		}

		// handle events
		sf::Event event;
		handleEvent(event);
		Move();
		touched = isTouched();
		if (touched){
			egg->setLife( egg->getLife() - 1 );
		}
		touched = false;
		Draw();
	}
}

void Game::Lose()
{
	window -> clear();
	count_life.setFont(count_life_font);
	count_life.setString("GAME OVER");
	count_life.setCharacterSize(50);
	count_life.setColor(sf::Color::Red);
	count_life.setStyle(sf::Text::Bold);
	count_life.setPosition(400,300);
	window -> draw(count_life);
	window->display();

	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();
	std::this_thread::sleep_for (std::chrono::seconds(3));
	sound.stop();
	window->close();
}


void Game::Draw()
{
	window->clear(sf::Color(228, 174, 10));

	// draw SFML content

	for(int i=0; i<4; i++)
	{
		spoons[i]->Draw(*window);
		chopsticks[i]->Draw(*window);
		bacons[i]->Draw(*window);
		forks[i]->Draw(*window);
		forks2[i]->Draw(*window);
		toasts[i]->Draw(*window);
		toasts2[i]->Draw(*window);
		bacons2[i]->Draw(*window);
	}
	toastFinal->Draw(*window);
	bed->Draw(*window);
	egg->Draw(*window);

	// draw text
	count_life.setFont(count_life_font);
	count_life.setString("SCORE :");
	count_life.setCharacterSize(15);
	count_life.setColor(sf::Color::White);
	count_life.setStyle(sf::Text::Bold);
	count_life.setPosition(0,0);
	window -> draw(count_life);

	// draw life
for(int i=0; i< (int)egg->getLife()/1000 +1; i++)
{
	lives[i] -> Draw(*window);
}

	window->display();
}


void Game::Move()
{
	for(int i=0; i<4; i++)
	{
		spoons[i]->Move(window->getSize());
		chopsticks[i]->Move(window->getSize());
		forks[i]->Move(window->getSize());
		forks2[i]->Move(window->getSize());
		bacons[i]->Move(window->getSize());
		toasts[i]->Move(window->getSize());

		bacons2[i]->Move(window->getSize());
		toasts2[i]->Move(window->getSize());
	}
	toastFinal->Move(window->getSize());
}


void Game::handleEvent(sf::Event event)
{
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
		{
			egg->Move(event, window->getSize());
			break;
		}

		case sf::Event::Closed:
		{
			window->close();
			break;
		}

		default:
			break;
		}
	}
}

bool Game::isTouched()
{
	for(int i=0; i<4; i++)
	{
		if (egg->GetShape().getGlobalBounds().intersects(spoons[i]->GetShape().getGlobalBounds()) ||
				egg->GetShape().getGlobalBounds().intersects(chopsticks[i]->GetShape().getGlobalBounds()) ||
				egg->GetShape().getGlobalBounds().intersects(forks[i]->GetShape().getGlobalBounds()) ||
				egg->GetShape().getGlobalBounds().intersects(forks[i]->GetShape().getGlobalBounds()))
		{
			return true;
		}
	}


	for(int i=0; i<4; i++)
	{
		if (egg->GetShape().getGlobalBounds().intersects(bacons[i]->GetShape().getGlobalBounds()))
		{
			 egg->Move(window->getSize(), bacons[i]->getSpeed());
			 return false;
		}
		else if (egg->GetShape().getGlobalBounds().intersects(toasts[i]->GetShape().getGlobalBounds()))
		{
			 egg->Move(window->getSize(), toasts[i]->getSpeed());
			 return false;
		}
		else if (egg->GetShape().getGlobalBounds().intersects(bacons2[i]->GetShape().getGlobalBounds()))
		{
			 egg->Move(window->getSize(), bacons2[i]->getSpeed());
			 return false;
		}
		else if (egg->GetShape().getGlobalBounds().intersects(toasts2[i]->GetShape().getGlobalBounds()))
		{
			 egg->Move(window->getSize(), toasts2[i]->getSpeed());
			 return false;
		}
		else if (egg->GetShape().getGlobalBounds().intersects(toastFinal->GetShape().getGlobalBounds()))
		{
			 egg->Move(window->getSize(), toastFinal->getSpeed());
			 return false;
		}
	}

		//si on est en haut de la fenêtre on ne peut pas toucher le sol
		if(egg->GetShape().getPosition().y < 400)
			{
				bool isCollision = false;
				for(int i = 0; i<4; i++)
				{
					isCollision = egg->GetShape().getGlobalBounds().intersects(bacons[i]->GetShape().getGlobalBounds()) ||
												egg->GetShape().getGlobalBounds().intersects(toasts[i]->GetShape().getGlobalBounds()) ||
												egg->GetShape().getGlobalBounds().intersects(bacons2[i]->GetShape().getGlobalBounds()) ||
												egg->GetShape().getGlobalBounds().intersects(toasts2[i]->GetShape().getGlobalBounds()) ||
												isCollision;
				}
				isCollision = egg->GetShape().getGlobalBounds().intersects(toastFinal->GetShape().getGlobalBounds()) ||
											isCollision;
				//si il n'y a collision avec aucun composant -> egg touche le sol
				if(!isCollision)
				{
					egg->GetShape().setPosition(490.0f, 600.0f);
					egg->GetShape().setFillColor(sf::Color::Black);
					std::cout<<"x : "<<egg->GetShape().getPosition().x<<"\t  y : "<<egg->GetShape().getPosition().y<<std::endl;
					return true;
				}
			}
			return false;
}
