#include "StartScene.h"

#include "GameScene.h"


StartScene::StartScene()
{
	finished = false;
	circle.setPosition(10, 10);
	circle.setRadius(10);
	circle.setFillColor(sf::Color(255, 0, 0, 255));

	if (!font.loadFromFile("./res/font/arial.ttf"))
	{
		//TODO: Log error properly
		std::cout << "Wasnt able to load arial.ttf from file!!" << std::endl;
	}

	title.setFont(font);
	title.setString("SPACE DEFENDER");
	title.setCharacterSize(45);
	title.setColor(sf::Color::Red);
	title.setPosition(200, 120);

	press.setFont(font);
	press.setString("Press Space to Start!");
	press.setCharacterSize(35);
	press.setColor(sf::Color::Blue);
	press.setPosition(230, 410);

}

void StartScene::render(sf::RenderWindow *window)
{
	window->draw(circle);
	window->draw(title);
	window->draw(press);
}

void StartScene::update(const sf::Time &elapsed)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		finished = true;
}

Scene* StartScene::swap()
{
	return new GameScene();
}

StartScene::~StartScene()
{
}
