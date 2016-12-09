#include "LayerLogo.h"

USING_NS_CC;
using namespace ui;

LayerLogo::LayerLogo() : _handleLogo(nullptr)
{
}

LayerLogo::~LayerLogo()
{
	CC_SAFE_RELEASE_NULL(_handleLogo);
}

bool LayerLogo::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Layer::init());

		_handleLogo = HandleLogo::create();
		_handleLogo->retain();
		_handleLogo->setLayerLogo(this);

		scheduleUpdate();

		isInit = true;
	} while (0);

	return isInit;
}

void LayerLogo::update(float delta)
{
	_handleLogo->update(delta);
}

void LayerLogo::addSkin(cocos2d::Layer* skin)
{
	addChild(skin);
}

void LayerLogo::playAnimation(cocos2d::Layer* skin, cocos2d::Action* action)
{
	skin->runAction(action);
}
