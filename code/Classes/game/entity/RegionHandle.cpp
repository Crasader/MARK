#include "Region.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

RegionHandle::RegionHandle()
{
}

RegionHandle::~RegionHandle()
{
}

bool RegionHandle::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!UnitHandle::init());

		isInit = true;
	} while (0);

	return isInit;
}

RegionModel* RegionHandle::createModel()
{
	auto model = RegionModel::create();
	model->retain();
	return model;
}
