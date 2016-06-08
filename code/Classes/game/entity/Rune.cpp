#include "Rune.h"

USING_NS_GAME_ENTITY;

Rune::Rune()
{
}

Rune::~Rune()
{
}

bool Rune::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Unit::init());

		isInit = true;
	} while (0);

	return isInit;
}
