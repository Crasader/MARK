#include "LayerMenuSystem.h"

USING_NS_CC;
using namespace ui;

LayerMenuSystem::LayerMenuSystem() : _handle(nullptr)
{
}

LayerMenuSystem::~LayerMenuSystem()
{
	CC_SAFE_RELEASE_NULL(_handle);
}

bool LayerMenuSystem::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Layer::init());

		_handle = LayerMenuSystemHandle::create();
		_handle->retain();
		_handle->setView(this);

		scheduleUpdate();

		isInit = true;
	} while (0);

	return isInit;
}

void LayerMenuSystem::update(float delta)
{
	_handle->update(delta);
}

void LayerMenuSystem::addLayer(Layer* layer)
{
	addChild(layer);
}

void LayerMenuSystem::addEvent(Button* btn, const std::string& titleName, const Widget::ccWidgetTouchCallback& onTouch)
{
	btn->setTitleText(titleName);
	btn->addTouchEventListener(onTouch);
}

void LayerMenuSystem::playAnimation(cocos2d::Layer* layer, cocos2d::Action* action)
{
	layer->runAction(action);
}
