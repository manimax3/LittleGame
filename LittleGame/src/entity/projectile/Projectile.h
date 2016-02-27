#pragma once
#include "../Entity.h"
#include <vector>

#define PROJ_VELOCITY 20.f

class Projectile : public Entity
{
	friend class ProjectileHandler;

public:
	inline sf::Vector2f& getPosition() { return position; }
	uint ID;
	~Projectile() {}
private:
	virtual void update(const sf::Time &elapsed) override;
	virtual void render(sf::RenderWindow *window) override;
	virtual void handleInput(const sf::Event &event) override;

	sf::Vector2f velocity;
	float maxLifeTime, remainingLifeTime;
	sf::Sprite sprite;

	Projectile();

	static uint ID_counter;
};