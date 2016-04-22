#include "ModelResLoad.h"

USING_NS_UI_COMMON;

ModelResLoad::ModelResLoad() : _state(StateResLoad::UNINIT), _numPlistNeedLoad(0)
{
}

ModelResLoad::~ModelResLoad()
{
	
}

bool ModelResLoad::init()
{
	auto isInit = false;

	do
	{
		isInit = true;
	} while (0);

	return isInit;
}
