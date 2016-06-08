#include "ModelResLoad.h"

USING_NS_UI_COMMON;

ModelResLoad::ModelResLoad() : _state(StateResLoad::UNINIT), _bitData(nullptr)
{
}

ModelResLoad::~ModelResLoad()
{
	CC_SAFE_RELEASE_NULL(_bitData);
}

bool ModelResLoad::init()
{
	auto isInit = false;

	do
	{
		isInit = true;

		_bitData = BitData::create();
		_bitData->retain();

	} while (0);

	return isInit;
}
