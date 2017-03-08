#include "Creature.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

CreatureHandle::CreatureHandle()
{
}

CreatureHandle::~CreatureHandle()
{
}

bool CreatureHandle::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!UnitHandle::init());

		isInit = true;
	} while (0);

	return isInit;
}

CreatureModel* CreatureHandle::createModel()
{
	auto model = CreatureModel::create();
	model->retain();
	return model;
}
