#pragma once
#include "../Entity.h"
#include "../projectile/ProjectileHandler.h"

#define PLAYER_VELOCITY 7

class Player : public Entity
{
public:
	virtual void update(const sf::Time &elapsed) override;
	virtual void render(sf::RenderWindow *window) override;
	virtual void handleInput(const sf::Event &event) override;

	Player();
	~Player();

private:
	sf::Sprite sprite;
	sf::Texture image;
	sf::Vector2f velocity, size, mousePos;
	float angle;
	bool up = false, down = false, right = false, left = false;

	ProjectileHandler projecHandler;
};