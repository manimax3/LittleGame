#include "AsteriodHandler.h"

using namespace sf;

AsteriodHandler::AsteriodHandler(ProjectileHandler &projecHandler)
	: projecHandler(projecHandler)
{
	if (!astTex.loadFromFile("./res/pics/asteroid.png"))
	{
		std::cout << "Unable to load Asteriod Image!!" << std::endl;
	}

	astSpr.setTexture(astTex);

}

void AsteriodHandler::render(RenderWindow *window)
{
	if (asteriods.size() == 0) return;
	for (auto ast : asteriods)
	{
		ast.render(window);
	}
}

uint AsteriodHandler::spawnAsteriod(Vector2f pos)
{
	Asteriod ast;
	ast.position = pos;
	ast.sprite = astSpr;
	float scale = (rand() % 10 + 1);
	ast.health = scale;
	
	ast.sprite.setScale(Vector2f(scale / 10, scale / 10));
	asteriods.push_back(ast);
	return ast.ID;
}

void AsteriodHandler::update(const Time &elapsed)
{
	for (auto &it = asteriods.begin(); it != asteriods.end(); ++it)
	{
	if (asteriods.size() == 0) break;
		for (auto &proj : projecHandler.getProjectiles())
		{
			if (it->sprite.getGlobalBounds().contains(proj.getPosition())) {
				it->health--;
				projecHandler.removeProjectile(proj.ID);
				continue;
			}
		}
		if (it->health <= 0) {
			asteriods.erase(it);
			break;
		}
			if (asteriods.size() == 0) break;
			it->update(elapsed);
	}
}