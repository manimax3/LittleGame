#pragma once
#include "Entity.h"
#include <iostream>

#define PI 3.14159265

class Player : public Entity
{
public:
	virtual void update(const sf::Time &elapsed) override;
	virtual void render(sf::RenderWindow *window) override;
	virtual void handleInput(const sf::Event &event) override;

	Player();
	~Player();

private:
	sf::Sprite sprite;
	sf::Texture image;
	sf::Vector2f velocity, size;
	bool winset = false;
	sf::RenderWindow *window;
	float angle;
	bool up = false, down = false, right = false, left = false;
};