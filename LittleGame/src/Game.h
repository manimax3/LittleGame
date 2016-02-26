#pragma once

#include "util\variables.h"
#include <iostream>
#include "SFML\Graphics.hpp"
#include "scene\StartScene.h"

#ifdef GLOBAL_DEBUG
#define DEBUG
#endif

class Game
{
public:
	Game();
	~Game();

	void start();
private:
	sf::RenderWindow *m_Window;
	Scene* scene;
	sf::Clock timer;
	bool focus = true;
#ifdef DEBUG
	sf::Clock second;
	int ticks = 0, frames = 0;
#endif
	void run();
	void render(sf::RenderWindow *window);
	void update(const sf::Time &elapsed);
	void pollEvents();
};

