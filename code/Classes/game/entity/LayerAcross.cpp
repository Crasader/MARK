#include "LayerAcross.h"

LayerAcross::LayerAcross() : _handleAcross(nullptr)
{
}

LayerAcross::~LayerAcross()
{
	CC_SAFE_RELEASE_NULL(_handleAcross);
}

bool LayerAcross::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Layer::init());

		_handleAcross = HandleAcross::create();
		_handleAcross->retain();
		_handleAcross->setLayerAcross(this);

		isInit = true;
	} while (0);

	return isInit;
}
