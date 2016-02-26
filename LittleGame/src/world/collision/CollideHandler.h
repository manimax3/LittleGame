#pragma once
#include "../../util/variables.h"
#include "SFML\Graphics.hpp"
#include "Collideable.h"
#include <vector>

class CollideHandler
{
public:
	void registerCollideable(Collideable *collide);
	void update();
private:
	std::vector<Collideable*> collideables;
public:
	static CollideHandler& instance()
	{
		static CollideHandler *instance = new CollideHandler();
		return *instance;
	}
private:
	CollideHandler();
};