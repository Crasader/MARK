#pragma execution_character_set("utf-8")

#include "LayerMenuSet.h"
#include "defines/DefinesRes.h"
#include "defines/DefinesValue.h"
#include "defines/DefinesString.h"
#include "cocostudio/ActionTimeline/CSLoader.h"

USING_NS_CC;
using namespace ui;

LayerMenuSet::LayerMenuSet() : _handle(nullptr)
{
}

LayerMenuSet::~LayerMenuSet()
{
	CC_SAFE_RELEASE_NULL(_handle);
}

bool LayerMenuSet::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Layer::init());

		_handle = LayerMenuSetHandle::create();
		_handle->retain();
		_handle->setView(this);

		scheduleUpdate();

		isInit = true;
	} while (0);

	return isInit;
}

void LayerMenuSet::update(float delta)
{
	_handle->update(delta);
}

void LayerMenuSet::addLayer(Layer* layer)
{
	addChild(layer);
}

void LayerMenuSet::addEvent(Button* btn, const std::string& titleName, const Widget::ccWidgetTouchCallback& onTouch)
{
	btn->setTitleText(titleName);
	btn->addTouchEventListener(onTouch);
}

void LayerMenuSet::playAnimation(cocos2d::Layer* layer, cocos2d::Action* action)
{
	layer->runAction(action);
}
