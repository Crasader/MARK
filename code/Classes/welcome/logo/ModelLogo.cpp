#include "ModelLogo.h"

ModelLogo::ModelLogo() : _state(StateLogo::SKIN_UNCREATE), _duration(0.0f)
{
}

ModelLogo::~ModelLogo()
{
}

bool ModelLogo::init()
{
	auto isInit = false;

	do
	{
		isInit = true;
	} while (0);

	return isInit;
}

void ModelLogo::addDuration(float val)
{
	_duration += val;
}

bool ModelLogo::isTimeOver()
{
	return _duration >= DURATION_TOTAL;
}
