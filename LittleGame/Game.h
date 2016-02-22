#pragma once

#include <iostream>
#include "SFML\Graphics.hpp"
#include "Scene.h"
#include "StartScene.h"

#define DEBUG

#define GAME_NAME "Little Game Test"
#define GAME_HEIGHT 400
#define GAME_WIDTH GAME_HEIGHT * 16 / 9

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

