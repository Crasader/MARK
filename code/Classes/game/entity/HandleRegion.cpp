#include "HandleRegion.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

HandleRegion::HandleRegion()
{
}

HandleRegion::~HandleRegion()
{
}

bool game::entity::HandleRegion::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!HandleUnit::init());

		isInit = true;
	} while (0);

	return isInit;
}

ModelRegion* HandleRegion::createModel()
{
	auto model = ModelRegion::create();
	model->retain();
	return model;
}
