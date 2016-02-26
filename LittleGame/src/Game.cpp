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
	m_Window->clear(sf::Color(0,0,0,255));
	m_Window->setVerticalSyncEnabled(true);
	scene = new StartScene();
	this->run();
}

void Game::run()
{

	double usPerTick = 1000000 / 60;
	double delta = 0; 

	//Time between frames parsed to update() -> weird
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

	scene->update(elapsed);

	if (scene->finished)
	{
		Scene* temp = scene->swap();
		delete scene;
		scene = temp;
	}

}

void Game::render(sf::RenderWindow *window)
{
#ifdef DEBUG
	frames++;
#endif

	m_Window->clear(sf::Color::Black);
	scene->render(m_Window);
	m_Window->display();
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
			
		scene->handleInput(event);

	}
}