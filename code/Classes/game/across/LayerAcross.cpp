#include "LayerAcross.h"

USING_NS_CC;
using namespace ui;

LayerAcross::LayerAcross() : _handle(nullptr)
{
}

LayerAcross::~LayerAcross()
{
	unscheduleUpdate();

	CC_SAFE_RELEASE_NULL(_handle);
}

bool LayerAcross::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Layer::init());

		_handle = LayerAcrossHandle::create();
		_handle->retain();
		_handle->setView(this);

		scheduleUpdate();

		isInit = true;
	} while (0);

	return isInit;
}

void LayerAcross::update(float delta)
{
	_handle->update(delta);
}

void LayerAcross::setContentSizeByAcrossObject(const cocos2d::Size& size)
{
	ignoreAnchorPointForPosition(false);
	setContentSize(size);
}

void LayerAcross::addEvent(cocos2d::EventListenerTouchOneByOne* listener)
{
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void LayerAcross::removeEvent(cocos2d::EventListenerTouchOneByOne* listener)
{
	_eventDispatcher->removeEventListener(listener);
}

void LayerAcross::addNodeTo(cocos2d::Node* node, const cocos2d::Vec2& postion)
{
	node->setPosition(postion);
	addChild(node);
}

void LayerAcross::refreshLine(cocos2d::Sprite* line, const float& rotation, const float& scaleX)
{
	line->setRotation(rotation);
	line->setScaleX(scaleX);
}
