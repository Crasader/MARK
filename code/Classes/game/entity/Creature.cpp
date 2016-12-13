#include "Creature.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

Creature::Creature()
{
}

Creature::~Creature()
{
}

bool Creature::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Unit::init());

		isInit = true;
	} while (0);

	return isInit;
}

void game::entity::Creature::addSkin(cocos2d::Sprite* skin)
{
	Unit::addSkin(skin);
}

HandleCreature* Creature::createHandle()
{
	auto handle = HandleCreature::create();
	handle->retain();
	handle->setEntity(this);
	return handle;
}
