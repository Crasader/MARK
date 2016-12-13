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

void game::entity::Region::addSkin(cocos2d::Sprite* skin)
{
	Unit::addSkin(skin);
}

HandleRegion* Region::createHandle()
{
	auto handle = HandleRegion::create();
	handle->retain();
	handle->setEntity(this);
	return handle;
}
