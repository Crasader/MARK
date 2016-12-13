#include "ModelRegion.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

ModelRegion::ModelRegion()
{
}

ModelRegion::~ModelRegion()
{
}

bool ModelRegion::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!ModelUnit::init());

		isInit = true;
	} while (0);

	return isInit;
}

Sprite* ModelRegion::createSprite()
{
	auto spriteFrameName = "images/map/ground.png";
	auto sprite = Sprite::createWithSpriteFrameName(spriteFrameName);
	return sprite;
}
