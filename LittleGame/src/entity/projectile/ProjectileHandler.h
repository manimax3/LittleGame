#pragma once
#include "../../util/variables.h"
#include "SFML\Graphics.hpp"
#include "Projectile.h"

class ProjectileHandler
{
public:
	ProjectileHandler();
private:
	std::vector<Projectile> projectiles;
	sf::Texture projTex;
	sf::Sprite projSpr;
public:
	void spawnProjectile(const sf::Vector2f &pos, const sf::Vector2f &dir, float maxLifeTime = 5.f);
	void update(const sf::Time &elapsed);
	void render(sf::RenderWindow *window);
};