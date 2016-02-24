#pragma once
#include "Player.h"

void Player::render(sf::RenderWindow *window)
{
	window->draw(sprite);
}

void Player::update(const sf::Time &elapsed)
{
	position += velocity * elapsed.asSeconds();


	sprite.setPosition(position);
	sprite.setRotation(angle);
}

Player::Player()
{
	image.loadFromFile("./res/pics/player.png");
	sprite.setTexture(image);
	sprite.setScale(sf::Vector2f(0.5, 0.5));
	position = sf::Vector2f(10, 10);
}

Player::~Player()
{

}