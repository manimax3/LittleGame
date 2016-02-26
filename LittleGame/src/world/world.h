#pragma once
#include "../util/variables.h"
#include "SFML\Graphics.hpp"

class World
{
	void render(sf::RenderWindow *window);
	void update(const sf::Time &elapsed);
	void handleInput(const sf::Event &event);
};