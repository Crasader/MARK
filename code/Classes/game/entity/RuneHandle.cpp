#include "Rune.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

RuneHandle::RuneHandle()
{
}

RuneHandle::~RuneHandle()
{
}

bool RuneHandle::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!UnitHandle::init());

		isInit = true;
	} while (0);

	return isInit;
}

RuneModel* RuneHandle::createModel()
{
	auto model = RuneModel::create();
	model->retain();
	return model;
}
