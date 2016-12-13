#include "ModelCreature.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

ModelCreature::ModelCreature()
{
}

ModelCreature::~ModelCreature()
{
}

bool ModelCreature::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!ModelUnit::init());

		isInit = true;
	} while (0);

	return isInit;
}

Sprite* ModelCreature::createSprite()
{
	auto spriteFrameName = "images/creature/creature.png";
	auto skin = Sprite::createWithSpriteFrameName(spriteFrameName);
	return skin;
}
