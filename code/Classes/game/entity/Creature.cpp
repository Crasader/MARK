#include "Creature.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

Creature::Creature()
{
}

Creature::~Creature()
{
}

bool Creature::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Unit::init());

		isInit = true;
	} while (0);

	return isInit;
}

void Creature::createSkin()
{
	auto spriteFrameName = "images/creature/creature.png";
	_skin = Sprite::createWithSpriteFrameName(spriteFrameName);

	Entity::createSkin();
}
