#include "LayerLogo.h"

USING_NS_CC;
using namespace cocostudio::timeline;
using namespace std;

LayerLogo::LayerLogo() : _handle(nullptr)
{
}

LayerLogo::~LayerLogo()
{
	unscheduleUpdate();
	CC_SAFE_RELEASE_NULL(_handle);
}

bool LayerLogo::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Layer::init());

		_handle = LayerLogoHandle::create();
		_handle->retain();
		_handle->setView(this);

		scheduleUpdate();

		isInit = true;
	} while (0);

	return isInit;
}

void LayerLogo::update(float delta)
{
	_handle->update(delta);
}

void LayerLogo::addSkin(cocos2d::Layer* skin)
{
	addChild(skin);
}

void LayerLogo::playAnimation(Layer* skin, ActionTimeline* action, const string& animationName, const bool& isLoop)
{
	action->play(animationName, isLoop);
	skin->runAction(action);
}
