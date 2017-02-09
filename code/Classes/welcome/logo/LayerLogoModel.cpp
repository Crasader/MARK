#include "LayerLogo.h"
#include "common/define/DefinesRes.h"

USING_NS_CC;
using namespace cocostudio::timeline;

LayerLogoModel::LayerLogoModel() : 
	_skin(nullptr),
	_duration(0.0f),
	_stateCallback()
{
	_stateCallback.setState(StateLayerLogo::CREATE_SKIN);
}

LayerLogoModel::~LayerLogoModel()
{
	_skin = nullptr;
}

bool LayerLogoModel::init()
{
	auto isInit = false;

	do
	{
		isInit = true;
	} while (0);

	return isInit;
}

Layer* LayerLogoModel::getSkin()
{
	if (_skin == nullptr)
	{
		_skin = (Layer*)CSLoader::createNode(RES_WELCOME_LOGO_LAYER_LOGO_CSB);
	}
	return _skin;
}

ActionTimeline* LayerLogoModel::getActionTimeline()
{
	/*cocostudio::timeline::ActionTimeline* actionTimeline;*/
	auto actionTimeline = CSLoader::createTimeline(RES_WELCOME_LOGO_LAYER_LOGO_CSB);
	return actionTimeline;
}

void LayerLogoModel::addDuration(float val)
{
	_duration += val;
}

bool LayerLogoModel::isTimeOver()
{
	return _duration >= DURATION_TOTAL;
}
