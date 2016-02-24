#pragma once
#include "SFML\Graphics.hpp"

class Entity
{
public:
	virtual void update(const sf::Time &elapsed) = 0;
	virtual void render(sf::RenderWindow *window) = 0;
protected:
	sf::Vector2f position;
};