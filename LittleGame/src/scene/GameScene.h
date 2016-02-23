#pragma once
#include "Scene.h"
class GameScene :
	public Scene
{
public:
	GameScene();
	~GameScene();

	virtual void update(const sf::Time& elapsed) override;
	virtual void render(sf::RenderWindow *window) override;
	virtual Scene* swap() override;
private:
	
};

