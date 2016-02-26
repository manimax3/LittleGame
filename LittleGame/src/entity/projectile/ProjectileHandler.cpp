#pragma once
#include "ProjectileHandler.h"

ProjectileHandler::ProjectileHandler()
{
	if (!projTex.loadFromFile("./res/pics/projec.png"))
		std::cout << "Could not load Projectile Texture" << std::endl;
	projSpr.setTexture(projTex);
	projSpr.setScale(sf::Vector2f(0.3, 0.3));
}

void ProjectileHandler::spawnProjectile(const sf::Vector2f &pos, const sf::Vector2f &dir, float maxLifeTime)
{
	Projectile proj;
	proj.position = pos;
	proj.velocity = dir * PROJ_VELOCITY;
	proj.maxLifeTime = maxLifeTime;
	proj.remainingLifeTime = maxLifeTime;
	proj.sprite = projSpr;
	projectiles.push_back(proj);
}

void ProjectileHandler::update(const sf::Time &elapsed)
{
	for (auto it = projectiles.begin(); it != projectiles.end(); ++it)
	{
		if (projectiles.size() == 0) break;
		if (it->remainingLifeTime <= 0) {
			projectiles.erase(it);
			continue;
		}
		if (projectiles.size() == 0) break;
		it->update(elapsed);
	}
}

void ProjectileHandler::render(sf::RenderWindow *window)
{
	for (auto pro : projectiles)
	{
		if (projectiles.size() == 0) break;
		pro.render(window);
	}
}