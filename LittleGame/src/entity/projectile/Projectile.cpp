#include "Projectile.h"

void Projectile::update(const sf::Time& elapsed)
{
	remainingLifeTime--;

	position += velocity;
	sprite.setPosition(position);
}

void Projectile::render(sf::RenderWindow *window)
{
	window->draw(sprite);
}

void Projectile::handleInput(const sf::Event &event)
{
	return;
}

