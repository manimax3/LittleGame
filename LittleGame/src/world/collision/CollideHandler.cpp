#include "CollideHandler.h"

void CollideHandler::registerCollideable(Collideable *collide)
{
	collideables.push_back(collide);
}

void CollideHandler::update()
{
	if ((collideables.size() == 0) || (collideables.size() == 1)) return;
	for (auto col : collideables)
	{
		if ((collideables.size() == 0) || (collideables.size() == 1)) break;
		sf::IntRect colRec(col->getPosition().x, col->getPosition().y,
			col->getSize().x, col->getSize().y);

		for (auto colother : collideables) 
		{
			if (col == colother) continue;
			if (!colother->shouldNotify()) continue;

			sf::IntRect colotherRec(colother->getPosition().x, colother->getPosition().y,
				colother->getSize().x, colother->getSize().y);

			if (colRec.intersects(colotherRec)) colother->didCollision(col->getType(), colother->getPosition());
		}
	}
}