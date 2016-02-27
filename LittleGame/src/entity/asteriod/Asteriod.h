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
protected:
	float health, maxHealth;
	sf::Sprite sprite;
	Asteriod();
private:
	static uint ID_counter;
};