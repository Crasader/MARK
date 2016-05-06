#include "LayerMenuSystem.h"
#include "cocostudio/ActionTimeline/CSLoader.h"
#include "model/define/DefinesRes.h"
#include "ui/UIButton.h"
#include "model/define/DefinesString.h"

USING_NS_CC;
using namespace ui;

LayerMenuSystem::LayerMenuSystem() : _handleMenuSystem(nullptr)
{
}

LayerMenuSystem::~LayerMenuSystem()
{
	CC_SAFE_RELEASE_NULL(_handleMenuSystem);
}

bool LayerMenuSystem::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Layer::init());

		_skin = (Layer*)CSLoader::createNode(RES_UI_MENU_LAYER_MENU_SYSTEM_CSB);
		addChild(_skin);

		auto btn = (Button *)_skin->getChildByName(btn0);
		btn->setTitleText(STR_MENU_SYSTEM);
		btn->addTouchEventListener(CC_CALLBACK_2(LayerMenuSystem::onTouchBtn, this));

		btn = (Button *)_skin->getChildByName(btn1);
		btn->setTitleText(STR_MENU_SOUND);
		btn->addTouchEventListener(CC_CALLBACK_2(LayerMenuSystem::onTouchBtn, this));

		_handleMenuSystem = HandleMenuSystem::create();
		_handleMenuSystem->retain();
		_handleMenuSystem->setLayerMenuSystem(this);

		isInit = true;
	} while (0);

	return isInit;
}

void LayerMenuSystem::onTouchBtn(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::ENDED)
	{
		auto btn = (Button*)ref;
		auto name = btn->getName();
		if (name == btn0)//
		{
			_handleMenuSystem->gameSetting();
		}
		else if (name == btn1)//
		{
			_handleMenuSystem->gameSounds();
		}
	}
}
