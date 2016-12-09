#include "ModelLogo.h"
#include "common/define/DefinesRes.h"

USING_NS_CC;
using namespace cocostudio::timeline;

ModelLogo::ModelLogo() : 
	_skin(nullptr),
	_state(StateLogo::CREATE_SKIN), 
	_duration(0.0f)
{
}

ModelLogo::~ModelLogo()
{
	_skin = nullptr;
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

Layer* ModelLogo::getSkin()
{
	if (_skin == nullptr)
	{
		_skin = (Layer*)CSLoader::createNode(RES_WELCOME_LOGO_LAYER_LOGO_CSB);
	}
	return _skin;
}

ActionTimeline* ModelLogo::getAnimation(const std::string& animationName, const bool& isLoop)
{
	/*cocostudio::timeline::ActionTimeline* actionTimeline;*/
	auto actionTimeline = CSLoader::createTimeline(RES_WELCOME_LOGO_LAYER_LOGO_CSB);
	actionTimeline->play(animationName, isLoop);
	return actionTimeline;
}

void ModelLogo::addDuration(float val)
{
	_duration += val;
}

bool ModelLogo::isTimeOver()
{
	return _duration >= DURATION_TOTAL;
}
