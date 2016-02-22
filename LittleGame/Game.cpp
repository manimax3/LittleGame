#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
	delete m_Window;
}

void Game::start()
{
	m_Window = new sf::RenderWindow(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), GAME_NAME);
	this->run();
}

void Game::run()
{

	double usPerTick = 1000000 / 60;
	double delta = 0; 
	sf::Time elapsed;

	timer.restart();

	while (m_Window->isOpen())
	{
		if (focus)
		{
			elapsed = timer.restart();
			delta += elapsed.asMicroseconds() / usPerTick;
		}
		else
		{
			timer.restart();
			elapsed = timer.getElapsedTime();
		}

		//std::cout << delta << std::endl;
		while (delta >= 1) {
			update(elapsed);
			delta--;
		}
		render(m_Window);
		pollEvents();

#ifdef DEBUG
		if (second.getElapsedTime().asSeconds() >= 1)
		{
			std::cout << "Ticks: " << ticks << " FPS: " << frames << std::endl;
			std::cout << "UPT: " << second.getElapsedTime().asSeconds() << std::endl;
			second.restart();
			frames = 0;
			ticks = 0;
		}
#endif
	}
}

void Game::update(const sf::Time &elapsed)
{
#ifdef DEBUG
	ticks++;
#endif




}

void Game::render(sf::RenderWindow *window)
{
#ifdef DEBUG
	frames++;
#endif




}

void Game::pollEvents()
{
	sf::Event event;

	while (m_Window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_Window->close();
		if (event.type == sf::Event::LostFocus)
			focus = false;
		if (event.type == sf::Event::GainedFocus)
			focus = true;
	}
}