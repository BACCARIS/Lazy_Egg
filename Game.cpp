#include <iostream>
#include "Game.h"

Game::Game()
{

	window = new sf::RenderWindow(sf::VideoMode(1000, 700), "Lazy Egg");

	egg = new Egg(window->getSize());
	bed = new Bed(window->getSize());
	toastFinal = new Toast(window->getSize(), sf::Vector2f(TOAST_FINAL_SIZE_X, TOAST_FINAL_SIZE_Y), TOAST_FINAL_POS_X, TOAST_FINAL_POS_Y);

	for(int i=0; i<4; i++)
	{
		//spoon/chopstick/fork
		Spoon* spoon = new Spoon(window->getSize(), i * 250, SPOON_POS_Y);
		spoons.push_back(spoon);
		Chopstick* chopstick = new Chopstick(window->getSize(), i * 250, CHOPSTICK_POS_Y);
		chopsticks.push_back(chopstick);
		Fork* fork = new Fork(window->getSize(), i * 250, FORK1_POS_Y);
		forks.push_back(fork);
		fork = new Fork(window->getSize(), i * 250, FORK2_POS_Y);
		forks2.push_back(fork);

		//toast/bacon
		Toast* toast = new Toast(window->getSize(), sf::Vector2f(TOAST1_SIZE_X, TOAST1_SIZE_Y), i * 250, TOAST1_POS_Y);
		toasts.push_back(toast);
		Bacon* bacon = new Bacon(window->getSize(),  sf::Vector2f(BACON1_SIZE_X, BACON1_SIZE_Y), i * 250, BACON1_POS_Y);
		bacons.push_back(bacon);
		toast = new Toast(window->getSize(), sf::Vector2f(TOAST2_SIZE_X, TOAST2_SIZE_Y), i * 650, TOAST2_POS_Y);
		toasts2.push_back(toast);
		bacon = new Bacon(window->getSize(), sf::Vector2f(BACON2_SIZE_X, BACON2_SIZE_Y),  i * 100, BACON2_POS_Y);
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

	// set sound bufferGameOver
		if (!bufferGameOver.loadFromFile("sounds/game_over.wav")){
		std::cout<<"sound game_over not found"<<std::endl;
	}

		// set sound buffer
		if (!bufferLoose.loadFromFile("sounds/loose.wav")){
		std::cout<<"sound loose not found"<<std::endl;
	}

	// set sound buffer
	if (!bufferWin.loadFromFile("sounds/win.wav")){
	std::cout<<"sound win not found"<<std::endl;
}

}


Game::~Game()
{
	delete window;
	delete egg;
	delete bed;
	delete toastFinal;
	for(int i = 0; i<4; i++)
	{
		delete chopsticks[i];
		delete spoons[i];
		delete forks[i];
		delete forks2[i];
		delete toasts[i];
		delete toasts2[i];
		delete bacons[i];
		delete bacons2[i];

	}

}



void Game::Loop()
{
	bool touched = false;

	while (window->isOpen())
	{
		// Decide win or loose
		if(!egg->getLife()) GameOver();

		// handle events
		sf::Event event;
		handleEvent(event);
		Move();
		touched = isTouched();
		if(isWon())
		{
			Win();
		}
		if (touched)
		{
			egg->setLife( egg->getLife() - 1000 );
			sf::Sound sound;
			sound.setBuffer(bufferLoose);
			sound.play();
			std::this_thread::sleep_for (std::chrono::seconds(1));
			sound.stop();
			egg->setPosition(sf::Vector2f(500, 650));
		}

		touched = false;

		Draw();
	}
}



void Game::GameOver()
{
	sf::Texture texture;
	sf::Sprite gudetamaSad;
	if (!texture.loadFromFile("sprite/gudetama_sad.png"))
	{
		std::cout<<"Image gudetama_sad not found"<<std::endl;
	}

	window -> clear();
	count_life.setFont(count_life_font);
	count_life.setString("GAME OVER");
	count_life.setCharacterSize(50);
	count_life.setColor(sf::Color::Red);
	count_life.setStyle(sf::Text::Bold);
	count_life.setPosition(400,200);


	gudetamaSad.setTexture(texture);
	gudetamaSad.setScale(sf::Vector2f(0.6, 0.6));
	gudetamaSad.setPosition(sf::Vector2f(300, 250));
	window -> draw(gudetamaSad);


	window -> draw(count_life);
	window->display();

	sf::Sound sound;
	sound.setBuffer(bufferGameOver);
	sound.play();
	std::this_thread::sleep_for (std::chrono::seconds(4));
	sound.stop();
	window->close();
}


void Game::Draw()
{
	//background Color
	window->clear(sf::Color(228, 174, 10));

	// draw SFML content
	drawContent();

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


void Game::drawContent()
{
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
}

//Move SFML componants
void Game::Move()
{
	for(int i=0; i<4; i++)
	{
		spoons[i]->Move(window->getSize(), SPOON_SPEED);
		chopsticks[i]->Move(window->getSize(),  CHOPSTICK_SPEED);
		forks[i]->Move(window->getSize(), FORK1_SPEED);
		forks2[i]->Move(window->getSize(), FORK2_SPEED);
		bacons[i]->Move(window->getSize(), BACON1_SPEED);
		toasts[i]->Move(window->getSize(), TOAST1_SPEED);

		bacons2[i]->Move(window->getSize(), BACON2_SPEED);
		toasts2[i]->Move(window->getSize(), TOAST2_SPEED);
	}
	toastFinal->Move(window->getSize(), TOAST_FINAL_SPEED);
}

//move egg if keyboard event
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

//vérifie si le perso touche le sol (si position y < 400)
//ou collision avec les spoon/fork/chopstick
bool Game::isTouched()
{
	if(isCollision()) return true;

	if(moveEgg()) return false;

	//si on est en haut de la fenêtre on ne peut pas toucher le sol
	if(egg->GetShape().getPosition().y < 400 && isOnFloor())
		{
			return true;
		}
	return false;
}


//check collision with spoon/chopstick/fork
bool Game::isCollision()
{
	for(int i=0; i<4; i++)
	{
		if (egg->GetShape().getGlobalBounds().intersects(spoons[i]->GetShape().getGlobalBounds()) ||
				egg->GetShape().getGlobalBounds().intersects(chopsticks[i]->GetShape().getGlobalBounds()) ||
				egg->GetShape().getGlobalBounds().intersects(forks[i]->GetShape().getGlobalBounds()) ||
				egg->GetShape().getGlobalBounds().intersects(forks2[i]->GetShape().getGlobalBounds()))
		{
			return true;
		}
	}
	return false;
}

//check if the egg is in contact with toast/bacon
//move the egg if true
bool Game::moveEgg()
{
	for(int i=0; i<4; i++)
	{
		if (egg->GetShape().getGlobalBounds().intersects(bacons[i]->GetShape().getGlobalBounds()))
		{
			 egg->Move(window->getSize(), bacons[i]->getSpeed());
			 return true;
		}
		else if (egg->GetShape().getGlobalBounds().intersects(toasts[i]->GetShape().getGlobalBounds()))
		{
			 egg->Move(window->getSize(), toasts[i]->getSpeed());
			 return true;
		}
		else if (egg->GetShape().getGlobalBounds().intersects(bacons2[i]->GetShape().getGlobalBounds()))
		{
			 egg->Move(window->getSize(), bacons2[i]->getSpeed());
			 return true;
		}
		else if (egg->GetShape().getGlobalBounds().intersects(toasts2[i]->GetShape().getGlobalBounds()))
		{
			 egg->Move(window->getSize(), toasts2[i]->getSpeed());
			 return true;
		}
		else if (egg->GetShape().getGlobalBounds().intersects(toastFinal->GetShape().getGlobalBounds()))
		{
			 egg->Move(window->getSize(), toastFinal->getSpeed());
			 return true;
		}
	}
	return false;
}


//check if the egg is on floor
bool Game::isOnFloor()
{
	bool isOnComposant = false;
	for(int i = 0; i<4; i++)
	{
		isOnComposant = egg->GetShape().getGlobalBounds().intersects(bacons[i]->GetShape().getGlobalBounds()) ||
									egg->GetShape().getGlobalBounds().intersects(toasts[i]->GetShape().getGlobalBounds()) ||
									egg->GetShape().getGlobalBounds().intersects(bacons2[i]->GetShape().getGlobalBounds()) ||
									egg->GetShape().getGlobalBounds().intersects(toasts2[i]->GetShape().getGlobalBounds()) ||
									isOnComposant;
	}

	isOnComposant = egg->GetShape().getGlobalBounds().intersects(toastFinal->GetShape().getGlobalBounds()) ||
								isOnComposant;

	//si il n'y a collision avec aucun composant -> egg touche le sol
	if(!isOnComposant)
	{
		egg->GetShape().setPosition(490.0f, 600.0f);
		return true;
	}
	return false;
}

//contact avec le lit -> win
bool Game::isWon()
{
	 return egg->GetShape().getGlobalBounds().intersects(bed->GetShape().getGlobalBounds());
}


void Game::Win()
{
	window->clear(sf::Color(228, 174, 10));
	sf::Texture texture;
	sf::Sprite gudetamaSleeping;


	sf::Sound sound;
	sound.setBuffer(bufferWin);
	sound.play();


	if (!texture.loadFromFile("sprite/gudetama_sleeping.png"))
	{
		std::cout<<"Image gudetama_sleeping not found"<<std::endl;
	}
	count_life.setFont(count_life_font);
	count_life.setString("YOU WIN !");
	count_life.setCharacterSize(50);
	count_life.setColor(sf::Color::Black);
	count_life.setStyle(sf::Text::Bold);
	count_life.setPosition(400,200);


	gudetamaSleeping.setTexture(texture);
	gudetamaSleeping.setScale(sf::Vector2f(0.6, 0.6));
	gudetamaSleeping.setPosition(sf::Vector2f(300, 250));

	window -> draw(count_life);
	window -> draw(gudetamaSleeping);

	window->display();
	std::this_thread::sleep_for (std::chrono::seconds(4));
	sound.stop();
	window->close();
}
