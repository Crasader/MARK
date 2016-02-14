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
		CC_BREAK_IF(Node::init());

		isInit = true;
	} while (0);

	return isInit;
}
