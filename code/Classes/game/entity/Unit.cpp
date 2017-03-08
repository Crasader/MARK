#include "Unit.h"

USING_NS_GAME_ENTITY;

Unit::Unit()
{
}

Unit::~Unit()
{
	
}

bool Unit::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Entity::init());

		isInit = true;
	} while (0);

	return isInit;
}

void game::entity::Unit::addSkin(cocos2d::Sprite* skin)
{
	Entity::addSkin(skin);
}

UnitHandle* Unit::createHandle()
{
	auto handle = UnitHandle::create();
	handle->retain();
	handle->setView(this);
	return handle;
}
