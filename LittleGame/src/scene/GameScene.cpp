#include "GameScene.h"

#include "../entity/player/Player.h"

GameScene::GameScene()
{
	finished = false;
}

void GameScene::update(const sf::Time& elapsed)
{
	handler.update(elapsed);
}

void GameScene::render(sf::RenderWindow *window)
{
	handler.render(window);
}

void GameScene::handleInput(const sf::Event &event)
{
	handler.handleInput(event);
}

Scene* GameScene::swap()
{
	return nullptr;
}

GameScene::~GameScene()
{
}
