#include "Entity.h"

bool Entity::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(Node::init());

		isInit = false;
	} while (0);

	return isInit;
}
