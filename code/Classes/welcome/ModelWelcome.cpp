#include "ModelWelcome.h"

ModelWelcome::ModelWelcome() : _listener(nullptr)
{
}

ModelWelcome::~ModelWelcome()
{
	_listener = nullptr;
}

bool ModelWelcome::init()
{
	auto isInit = false;

	do
	{
		isInit = true;
	} while (0);

	return isInit;
}
