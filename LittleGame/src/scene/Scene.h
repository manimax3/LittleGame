#pragma once

#include "SFML\Graphics.hpp"


class Scene
{
public:

	bool finished;

	Scene() {};
	~Scene() {};

	virtual void update(const sf::Time &elapsed) = 0;
	virtual void render(sf::RenderWindow *window) = 0;

	//Check if finished before
	virtual Scene* swap() = 0;

	//Can be used to preload larger scenes
	//virtual void load();
	//virtual Scene* request();
};