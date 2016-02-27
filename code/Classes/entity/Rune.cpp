#include "Rune.h"

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
		CC_BREAK_IF(!Entity::init());

		isInit = true;
	} while (0);

	return isInit;
}
