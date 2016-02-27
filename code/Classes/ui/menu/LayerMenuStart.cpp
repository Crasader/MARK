#include "LayerMenuStart.h"
#include "model/define/DfinesRes.h"
#include "cocostudio/ActionTimeline/CSLoader.h"
#include "ui/UIButton.h"

USING_NS_CC;
using namespace ui;

LayerMenuStart::LayerMenuStart() : _handleMenuStart(nullptr)
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

		_skin = (Layer *)CSLoader::createNode(RES_LAYER_MAIN);
		addChild(_skin);

		auto btn = (Button *)_skin->getChildByName(btn0);
		btn->addTouchEventListener(CC_CALLBACK_2(LayerMenuStart::onTouchBtn, this));
		btn = (Button *)_skin->getChildByName(btn1);
		btn->addTouchEventListener(CC_CALLBACK_2(LayerMenuStart::onTouchBtn, this));
		btn = (Button *)_skin->getChildByName(btn2);
		btn->addTouchEventListener(CC_CALLBACK_2(LayerMenuStart::onTouchBtn, this));

		_handleMenuStart = new HandleMenuStart();
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
