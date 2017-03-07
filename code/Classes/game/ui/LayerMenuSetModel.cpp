#include "LayerMenuSet.h"
#include "cocostudio/ActionTimeline/CSLoader.h"
#include "common/define/DefinesRes.h"

USING_NS_CC;
using namespace ui;

LayerMenuSetModel::LayerMenuSetModel() :
	_stateCallback(StateLayerMenuSet::CREATE_SKIN),
	_skin(nullptr),
	_vecBtns()
{
}

LayerMenuSetModel::~LayerMenuSetModel()
{
	_vecBtns.clear();
	_skin = nullptr;
	_stateCallback.clearDic();
}

bool LayerMenuSetModel::init()
{
	auto isInit = false;

	do
	{
		isInit = true;
	} while (0);

	return isInit;
}

cocos2d::Layer* LayerMenuSetModel::getSkin()
{
	if (_skin == nullptr)
	{
		_skin = (Layer*)CSLoader::createNode(RES_GAME_UI_MENU_LAYER_MENU_SET_CSB);
		_skin->setOpacity(0);
	}
	return _skin;
}

const cocos2d::Vector<cocos2d::ui::Button*>& LayerMenuSetModel::getVecBtns()
{
	if (_vecBtns.size() == 0)
	{
		auto i = 0;
		Button* btn = nullptr;
		do
		{
			btn = (Button*)_skin->getChildByName("btn" + Value(i).asString());
			CC_BREAK_IF(btn == nullptr);
			_vecBtns.pushBack(btn);
			i++;
		} while (1);
	}
	return _vecBtns;
}

cocos2d::Action* LayerMenuSetModel::getAnimation()
{
	auto duration = 1.0f;
	_skin->setOpacity(0);
	/*_skin->setVisible(true);*/
	/*_skin->setScale(10.0f);*/

	/*auto actionSpawn = Spawn::createWithTwoActions(EaseCubicActionIn::create(FadeIn::create(d)), EaseCubicActionIn::create(ScaleTo::create(d, 1.0f)));*/

	/*auto durationShake = 0.4f;
	auto actionShake = Spawn::createWithTwoActions(DelayTime::create(durationShake), CallFunc::create([this, durationShake]()
	{
	auto node = getParent()->getParent();
	node->runAction(Shake::create(durationShake, 1.5f));
	}));*/
	auto actionFadeIn = EaseCubicActionIn::create(FadeIn::create(duration));

	auto actionCallFunc = CallFunc::create([&]()
	{
		_skin->setOpacity(255);
		_isAnimationPlayOver = true;
	});

	auto action = Sequence::create(actionFadeIn, actionCallFunc, nullptr);
	return action;
}
