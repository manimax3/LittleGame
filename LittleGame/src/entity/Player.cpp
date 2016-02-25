#pragma once
#include "Player.h"

void Player::render(sf::RenderWindow *window)
{
	if (!winset)
	{
		this->window = window;
		winset = true;
	}
	window->draw(sprite);
}

void Player::update(const sf::Time &elapsed)
{

	if (winset)
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
		float dx = mousePos.x - position.x;
		float dy = mousePos.y - position.y;

		angle = -atan2(dx, dy) * 180 / PI + 180;
	}

	if (up) velocity.y = -10;
	if (down) velocity.y = 10;
	if (right) velocity.x = 10;
	if (left) velocity.x = -10;

	if (up && down) velocity.y = 0;
	if (left && right) velocity.x = 0;

	position += velocity * elapsed.asSeconds();
	sprite.setPosition(position);
	sprite.setRotation(angle);
	
}

void Player::handleInput(const sf::Event &event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::A)
			left = true;
		if (event.key.code == sf::Keyboard::S)
			down = true;
		if (event.key.code == sf::Keyboard::D)
			right = true;
		if (event.key.code == sf::Keyboard::W)
			up = true;
	}
	else if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::A)
			left = false;
		if (event.key.code == sf::Keyboard::S)
			down = false;
		if (event.key.code == sf::Keyboard::D)
			right = false;
		if (event.key.code == sf::Keyboard::W)
			up = false;
	}
}

Player::Player()
{
	image.loadFromFile("./res/pics/player.png");
	sprite.setTexture(image);
	sprite.setScale(sf::Vector2f(0.5, 0.5));
	sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2));
	position = sf::Vector2f(100, 100);
}

Player::~Player()
{

}