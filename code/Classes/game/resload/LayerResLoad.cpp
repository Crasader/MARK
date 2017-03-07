#pragma execution_character_set("utf-8")

#include "LayerResLoad.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;
using namespace std;

LayerResLoad::LayerResLoad() : _handle(nullptr)
{
}

LayerResLoad::~LayerResLoad()
{
	unscheduleUpdate();

	CC_SAFE_RELEASE_NULL(_handle);
}

bool LayerResLoad::init()
{
	auto isInit = false;

	do 
	{
		CC_BREAK_IF(!Layer::init());

		_handle = LayerResLoadHandle::create();
		_handle->retain();
		_handle->setView(this);

		scheduleUpdate();

		isInit = true;
	} while (0);

	return isInit;
}

void LayerResLoad::update(float delta)
{
	_handle->update(delta);
}

void LayerResLoad::addSkin(cocos2d::Node* skin)
{
	addChild(skin);
}

void LayerResLoad::playLoadAnimation(cocos2d::Node* node)
{
	node->runAction(RepeatForever::create(RotateBy::create(3.0f, 360.0f)));
}

void LayerResLoad::stopLoadAnimation(cocos2d::Node* node)
{
	node->stopAllActions();
}
