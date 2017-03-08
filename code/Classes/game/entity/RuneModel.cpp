#include "Rune.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

RuneModel::RuneModel()
{
}

RuneModel::~RuneModel()
{
}

bool RuneModel::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!UnitModel::init());

		isInit = true;
	} while (0);

	return isInit;
}

Sprite* RuneModel::createSprite()
{
	auto spriteFrameName = "";
	auto sprite = Sprite::createWithSpriteFrameName(spriteFrameName);
	return sprite;
}
