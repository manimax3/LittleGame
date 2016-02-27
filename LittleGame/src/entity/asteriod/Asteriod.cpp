#include "Asteriod.h"

using namespace sf;

void Asteriod::update(const Time &elapsed)
{
	sprite.setPosition(position);
}

void Asteriod::render(RenderWindow *window)
{
	window->draw(sprite);
}

Asteriod::Asteriod()
{
	this->ID = ID_counter++;
}

uint Asteriod::ID_counter = 0;