#pragma execution_character_set("utf-8")

#include "LayerMenuStart.h"
#include "common/define/DefinesRes.h"
#include "common/define/DefinesValue.h"
#include "common/define/DefinesString.h"
#include "cocostudio/ActionTimeline/CSLoader.h"
#include "ui/UIButton.h"

USING_NS_CC;
using namespace ui;

LayerMenuStart::LayerMenuStart() : _skin(nullptr), _handleMenuStart(nullptr)
{
}

LayerMenuStart::~LayerMenuStart()
{
	_skin = nullptr;
	CC_SAFE_RELEASE_NULL(_handleMenuStart);
}

bool LayerMenuStart::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Layer::init());

		_skin = (Layer *)CSLoader::createNode(RES_GAME_UI_MENU_LAYER_MENU_START_CSB);
		addChild(_skin);

		auto btn = (Button *)_skin->getChildByName(btn0);
		btn->setTitleText(STR_MENU_START);
		btn->addTouchEventListener(CC_CALLBACK_2(LayerMenuStart::onTouchBtn, this));

		btn = (Button *)_skin->getChildByName(btn1);
		btn->setTitleText(STR_MENU_SAVE_LOAD);
		btn->addTouchEventListener(CC_CALLBACK_2(LayerMenuStart::onTouchBtn, this));

		btn = (Button *)_skin->getChildByName(btn2);
		btn->setTitleText(STR_MENU_SETTING);
		btn->addTouchEventListener(CC_CALLBACK_2(LayerMenuStart::onTouchBtn, this));

		_handleMenuStart = LayerMenuStartHandle::create();
		_handleMenuStart->retain();
		_handleMenuStart->setLayerMenuStart(this);

		isInit = true;
	} while (0);

	return isInit;
}

void LayerMenuStart::onTouchBtn(cocos2d::Ref *ref, cocos2d::ui::Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::ENDED)
	{
		auto btn = (Button *)ref;
		auto name = btn->getName();
		if (name == btn0)
		{
			_handleMenuStart->gameStart();
		}
		else if (name == btn1)
		{
			_handleMenuStart->gameSaveLoad();
		}
		else if (name == btn2)
		{
			_handleMenuStart->gameSetting();
		}
	}
}
