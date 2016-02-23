#pragma once

#include <iostream>

#include "Scene.h"
class StartScene :
	public Scene
{
public:
	StartScene();
	~StartScene();

	virtual void update(const sf::Time& elapsed) override;
	virtual void render(sf::RenderWindow *window) override;
	virtual Scene* swap() override;

private:
	sf::CircleShape circle;
	sf::Font font;
	sf::Text title, press;
};

