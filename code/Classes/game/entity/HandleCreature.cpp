#include "HandleCreature.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

HandleCreature::HandleCreature()
{
}

HandleCreature::~HandleCreature()
{
}

bool HandleCreature::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!HandleUnit::init());

		isInit = true;
	} while (0);

	return isInit;
}

ModelCreature* HandleCreature::createModel()
{
	auto model = ModelCreature::create();
	model->retain();
	return model;
}
