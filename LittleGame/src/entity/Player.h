#pragma once
#include "Entity.h"
#include <iostream>

class Player : public Entity
{
public:
	virtual void update(const sf::Time &elapsed) override;
	virtual void render(sf::RenderWindow *window) override;

	Player();
	~Player();

private:
	sf::Sprite sprite;
	sf::Texture image;
	sf::Vector2f velocity, size;
	float angle;
};