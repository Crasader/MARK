#include "Region.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

RegionModel::RegionModel()
{
}

RegionModel::~RegionModel()
{
}

bool RegionModel::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!UnitModel::init());

		isInit = true;
	} while (0);

	return isInit;
}

Sprite* RegionModel::createSprite()
{
	auto spriteFrameName = "images/map/ground.png";
	auto sprite = Sprite::createWithSpriteFrameName(spriteFrameName);
	return sprite;
}
