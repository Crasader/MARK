#include "LayerLogo.h"
#include "defines/DefinesRes.h"

USING_NS_CC;
using namespace cocostudio::timeline;

LayerLogoModel::LayerLogoModel() : 
	_stateCallback(StateLayerLogo::CREATE_SKIN),
	_skin(nullptr),
	_duration(0.0f)
	
{
}

LayerLogoModel::~LayerLogoModel()
{
	_skin = nullptr;
	_stateCallback.clearDic();
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
