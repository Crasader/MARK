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

HandleUnit* Unit::createHandle()
{
	auto handle = HandleUnit::create();
	handle->retain();
	handle->setEntity(this);
	return handle;
}
