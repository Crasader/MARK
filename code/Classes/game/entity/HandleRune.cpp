#include "HandleRune.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

HandleRune::HandleRune()
{
}

HandleRune::~HandleRune()
{
}

bool HandleRune::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!HandleUnit::init());

		isInit = true;
	} while (0);

	return isInit;
}

ModelCreature* HandleRune::createModel()
{
	auto model = ModelCreature::create();
	model->retain();
	return model;
}
