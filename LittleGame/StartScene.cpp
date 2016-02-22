#include "StartScene.h"



StartScene::StartScene()
{
	finished = false;
	circle.setPosition(10, 10);
	circle.setRadius(10);
	circle.setFillColor(sf::Color(255, 0, 0, 255));
}

void StartScene::render(sf::RenderWindow *window)
{
	window->draw(circle);
}

void StartScene::update(const sf::Time &elapsed)
{

}

Scene* StartScene::swap()
{
	return nullptr;
}

StartScene::~StartScene()
{
}
