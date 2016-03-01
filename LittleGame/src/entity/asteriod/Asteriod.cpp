#include "Asteriod.h"

using namespace sf;

void Asteriod::update(const Time &elapsed)
{
	sprite.setPosition(position);
	sprite.setRotation(rotation++);
}

void Asteriod::render(RenderWindow *window)
{
	window->draw(sprite);
}

Asteriod::Asteriod()
{
	this->ID = ID_counter++;
	velocity = Vector2f(0, 0);
}

uint Asteriod::ID_counter = 0;