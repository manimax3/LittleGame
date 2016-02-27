#pragma once
#include "SFML\Graphics.hpp"
#include "../../util/variables.h"
#include <vector>
#include "../projectile/ProjectileHandler.h"
#include "Asteriod.h"

class AsteriodHandler
{


public:
	AsteriodHandler(ProjectileHandler &projec);
	uint spawnAsteriod(sf::Vector2f pos);
private:
	std::vector<Asteriod> asteriods;
	sf::Texture astTex;
	sf::Sprite astSpr;
public:
	void update(const sf::Time &elapsed);
	void render(sf::RenderWindow *window);
private:
	ProjectileHandler &projecHandler;
};