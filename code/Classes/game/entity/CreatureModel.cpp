#include "Creature.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

CreatureModel::CreatureModel()
{
}

CreatureModel::~CreatureModel()
{
}

bool CreatureModel::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!UnitModel::init());

		isInit = true;
	} while (0);

	return isInit;
}

Sprite* CreatureModel::createSprite()
{
	auto spriteFrameName = "images/creature/creature.png";
	auto skin = Sprite::createWithSpriteFrameName(spriteFrameName);
	return skin;
}
