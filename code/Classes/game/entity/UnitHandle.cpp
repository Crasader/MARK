#include "Unit.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

UnitHandle::UnitHandle()
{
}

UnitHandle::~UnitHandle()
{
}

bool UnitHandle::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!EntityHandle::init());

		isInit = true;
	} while (0);

	return isInit;
}

UnitModel* UnitHandle::createModel()
{
	auto model = UnitModel::create();
	model->retain();
	return model;
}
