#pragma once
#include "../../util/variables.h"
#include "SFML\Graphics.hpp"
#include "../Entity.h"

class Asteriod : public Entity
{
	friend class AsteriodHandler;

public:
	virtual void update(const sf::Time &elapsed) override;
	virtual void render(sf::RenderWindow *window) override;
	virtual void handleInput(const sf::Event &event) override {};
	uint ID;
	Asteriod();
protected:
	float health, maxHealth, rotation = 0;
	sf::Sprite sprite;
	sf::Vector2f velocity;
private:
	static uint ID_counter;
};