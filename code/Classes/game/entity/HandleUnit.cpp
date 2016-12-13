#include "HandleUnit.h"
#include "ModelUnit.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

HandleUnit::HandleUnit()
{
}

HandleUnit::~HandleUnit()
{
}

bool HandleUnit::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!HandleEntity::init());

		isInit = true;
	} while (0);

	return isInit;
}

ModelUnit* HandleUnit::createModel()
{
	auto model = ModelUnit::create();
	model->retain();
	return model;
}
