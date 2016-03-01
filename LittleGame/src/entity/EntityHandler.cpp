#include "EntityHandler.h"

using namespace sf;

EntityHandler::EntityHandler()
	: player(Player(projecHandler)), astroHandler(AsteriodHandler(projecHandler))
{

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