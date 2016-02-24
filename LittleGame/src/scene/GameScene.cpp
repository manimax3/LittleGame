#include "GameScene.h"

#include "../entity/Player.h"

GameScene::GameScene()
{
	finished = false;
}

void GameScene::update(const sf::Time& elapsed)
{
	player.update(elapsed);
}

void GameScene::render(sf::RenderWindow *window)
{
	player.render(window);
}

Scene* GameScene::swap()
{
	return nullptr;
}

GameScene::~GameScene()
{
}
