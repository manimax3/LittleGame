#pragma once
#include "../../util/variables.h"
#include "SFML\Graphics.hpp"

enum class COLLIDING_TYPE { PLAYER, ASTERIOD, PROJECTILE };

class Collideable
{
public:
	virtual void didCollision(COLLIDING_TYPE type, sf::Vector2f position) = 0;
	virtual inline sf::Vector2f getPosition() = 0;
	virtual inline sf::Vector2f getSize() = 0;
	virtual inline bool shouldNotify() = 0;
	virtual inline COLLIDING_TYPE getType() = 0;
};