#pragma once
#include "../util/variables.h"
#include "SFML\Graphics.hpp"
#include <iostream>

class Entity
{
public:
	virtual void update(const sf::Time &elapsed) = 0;
	virtual void render(sf::RenderWindow *window) = 0;
	virtual void handleInput(const sf::Event &event) = 0;
protected:
	sf::Vector2f position;
};