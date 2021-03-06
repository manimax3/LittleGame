#pragma once
#include "Scene.h"

#include "../entity/EntityHandler.h"
class GameScene :
	public Scene
{
public:
	GameScene();
	~GameScene();

	virtual void update(const sf::Time& elapsed) override;
	virtual void render(sf::RenderWindow *window) override;
	virtual void handleInput(const sf::Event &event) override;

	virtual Scene* swap() override;
private:
	EntityHandler handler;
};

