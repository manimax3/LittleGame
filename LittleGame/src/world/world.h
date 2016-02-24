#pragma once
#include "SFML\Graphics.hpp"

class world
{
public:
	void update(const sf::Time &elapsed);
	void render(sf::RenderWindow *window);
};