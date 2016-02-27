#pragma once
#include "Player.h"

using namespace std;

void Player::render(sf::RenderWindow *window)
{
	window->draw(sprite);
}

void Player::update(const sf::Time &elapsed)
{

	float dx = mousePos.x - position.x;
	float dy = mousePos.y - position.y;

	angle = -atan2(dx, dy) * 180 / PI + 180;


	//Keeping player inside the window
	if (position.x > GAME_WIDTH) right = false;
	if (position.y > GAME_HEIGHT) down = false;
	if (position.y < 0) up = false;
	if (position.x < 0) left = false;


	if (up) velocity.y = -PLAYER_VELOCITY;
	if (down) velocity.y = PLAYER_VELOCITY;
	if (right) velocity.x = PLAYER_VELOCITY;
	if (left) velocity.x = -PLAYER_VELOCITY;

	if (!up && !down) velocity.y = 0;
	if (!left && !right) velocity.x = 0;

	position += velocity;
	sprite.setPosition(position);
	sprite.setRotation(angle);
}

void Player::handleInput(const sf::Event &event)
{
	if (event.type == sf::Event::MouseMoved)
	{
		mousePos.x = event.mouseMove.x;
		mousePos.y = event.mouseMove.y;
		return;
	}
	else if (event.type == sf::Event::KeyPressed)
	{


		if (event.key.code == sf::Keyboard::A)
			left = true;
		if (event.key.code == sf::Keyboard::S)
			down = true;
		if (event.key.code == sf::Keyboard::D)
			right = true;
		if (event.key.code == sf::Keyboard::W)
			up = true;
		return;
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
		return;
	}
	else if (event.type == sf::Event::MouseButtonPressed)
	{
		projecHandler.spawnProjectile(position,
									  sf::Vector2f(cos((angle - 90) * DEG_IN_RAD) ,
												   sin((angle - 90) * DEG_IN_RAD)),
									  5 * 60);
	}

}

Player::Player(ProjectileHandler &projec)
	: projecHandler(projec)
{
	image.loadFromFile("./res/pics/player.png");
	sprite.setTexture(image);
	sprite.setScale(sf::Vector2f(0.3, 0.3));
	sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2));
	size.x = sprite.getLocalBounds().width;
	size.y = sprite.getLocalBounds().height;
	position = sf::Vector2f(100, 100);

}

Player::~Player()
{
}