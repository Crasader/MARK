#include "Unit.h"

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
