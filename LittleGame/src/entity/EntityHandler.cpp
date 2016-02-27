#include "EntityHandler.h"

using namespace sf;

EntityHandler::EntityHandler()
	: player(Player(projecHandler)), astroHandler(AsteriodHandler(projecHandler))
{
	astroHandler.spawnAsteriod(Vector2f(10, 10));
	astroHandler.spawnAsteriod(Vector2f(400, 50));
	astroHandler.spawnAsteriod(Vector2f(200, 60));
	astroHandler.spawnAsteriod(Vector2f(100, 200));
	//astroHandler.spawnAsteriod(Vector2f(10, 300));
	//astroHandler.spawnAsteriod(Vector2f(400, 200));
	//astroHandler.spawnAsteriod(Vector2f(200, 200));
	//astroHandler.spawnAsteriod(Vector2f(100, 10));
}

void EntityHandler::update(const Time &elapsed)
{
	player.update(elapsed);
	projecHandler.update(elapsed);
	astroHandler.update(elapsed);
}

void EntityHandler::render(RenderWindow *window)
{
	projecHandler.render(window);
	astroHandler.render(window);
	player.render(window);
}

void EntityHandler::handleInput(const Event &event)
{
	player.handleInput(event);
}