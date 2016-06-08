#include "Region.h"
#include <vector>

USING_NS_CC;
USING_NS_GAME_ENTITY;

Region::Region()
{

}

Region::~Region()
{

}

bool Region::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Unit::init());
		isInit = true;
	} while (0);

	return isInit;
}

void Region::createSkin()
{
	auto spriteFrameName = "images/map/ground.png";
	_skin = Sprite::createWithSpriteFrameName(spriteFrameName);
	
	Entity::createSkin();
}
