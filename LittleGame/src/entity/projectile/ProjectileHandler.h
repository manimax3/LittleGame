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
	uint spawnProjectile(const sf::Vector2f &pos, const sf::Vector2f &dir, float maxLifeTime = 5.f);
	void removeProjectile(uint ID);
	void update(const sf::Time &elapsed);
	void render(sf::RenderWindow *window);
	inline std::vector<Projectile>&  getProjectiles() {	return projectiles;	}
};