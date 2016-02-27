#pragma once
#include "../util/variables.h"
#include "SFML\Graphics.hpp"
#include "Entity.h"
#include "projectile\ProjectileHandler.h"
#include "asteriod\AsteriodHandler.h"
#include "player\Player.h"

class EntityHandler
{
	friend class Entity;
public:
	EntityHandler();
	ProjectileHandler projecHandler;
	AsteriodHandler astroHandler;
	Player player;

	void update(const sf::Time &elapsed);
	void render(sf::RenderWindow *window);
	void handleInput(const sf::Event &event);
};