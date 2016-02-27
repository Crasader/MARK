#include "Creature.h"

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
