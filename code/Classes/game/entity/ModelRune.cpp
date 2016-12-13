#include "ModelRune.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

ModelRune::ModelRune()
{
}

ModelRune::~ModelRune()
{
}

bool ModelRune::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!ModelUnit::init());

		isInit = true;
	} while (0);

	return isInit;
}

Sprite* ModelRune::createSprite()
{
	auto spriteFrameName = "";
	auto sprite = Sprite::createWithSpriteFrameName(spriteFrameName);
	return sprite;
}
