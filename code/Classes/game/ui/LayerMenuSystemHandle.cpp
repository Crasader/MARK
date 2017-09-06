#pragma execution_character_set("utf-8")

#include "LayerMenuSystem.h"
#include "defines/DefinesString.h"
#include <vector>
#include <string>
#include "game/ManagerHandle.h"
#include "defines/DefinesValue.h"

USING_NS_CC;
using namespace ui;

LayerMenuSystemHandle::LayerMenuSystemHandle() : _view(nullptr), _model(nullptr)
{
}

LayerMenuSystemHandle::~LayerMenuSystemHandle()
{
	_model = nullptr;
	_view = nullptr;
}

bool LayerMenuSystemHandle::init()
{
	auto isInit = false;

	do
	{
		_model = LayerMenuSystemModel::create();
		_model->retain();

		attachStateCallback();

		isInit = true;
	} while (0);

	return isInit;
}

void LayerMenuSystemHandle::attachStateCallback()
{
	auto& stateCallback = _model->getStateCallback();
	stateCallback.insertCallback(StateLayerMenuSystem::DEFAULT);
	stateCallback.insertCallback(StateLayerMenuSystem::CREATE_SKIN, CC_CALLBACK_0(LayerMenuSystemHandle::createSkin, this));
	stateCallback.insertCallback(StateLayerMenuSystem::ADD_EVENT, CC_CALLBACK_0(LayerMenuSystemHandle::addEvent, this));
	stateCallback.insertCallback(StateLayerMenuSystem::PLAY_ANIMATION, CC_CALLBACK_0(LayerMenuSystemHandle::playAnimation, this));
}

void LayerMenuSystemHandle::update(float delta)
{
	auto& stateCallback = _model->getStateCallback();
	stateCallback.doCallbackByCurrentState(delta);
}

void LayerMenuSystemHandle::createSkin()
{
	auto skin = _model->getSkin();
	_view->addLayer(skin);

	_model->setState(StateLayerMenuSystem::ADD_EVENT);
}

void LayerMenuSystemHandle::addEvent()
{
	std::vector<std::string> vecNames = { STR_MENU_SYSTEM, STR_MENU_SOUND };
	std::vector<std::function<void(Ref* ref, Widget::TouchEventType type)>> vecOnTouchs = 
	{ 
		CC_CALLBACK_2(LayerMenuSystemHandle::onTouchBtnSetting, this),
		CC_CALLBACK_2(LayerMenuSystemHandle::onTouchBtnSounds, this)
	};
	auto& vecBtns = _model->getVecBtns();
	auto length = vecBtns.size();
	for (auto i = 0; i < length; i++)
	{
		auto btn = vecBtns.at(i);
		_view->addEvent(btn, vecNames.at(i), vecOnTouchs.at(i));
	}

	_model->setState(StateLayerMenuSystem::PLAY_ANIMATION);
}

void LayerMenuSystemHandle::onTouchBtnSetting(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::ENDED)
	{
		auto btn = (Button*)ref;
		auto manager = ManagerHandle::getInstance();
		manager->notify((int)ID_OBSERVER::HANDLE_SCENE_GAME, TO_HANDLE_SCENE_GAME::LAYER_MENU_SET_SWITCH);
	}
}

void LayerMenuSystemHandle::onTouchBtnSounds(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::ENDED)
	{
		auto btn = (Button*)ref;
	}
}

void LayerMenuSystemHandle::playAnimation()
{
	auto skin = _model->getSkin();
	auto action = _model->getAnimation();
	_view->playAnimation(skin, action);

	_model->setState(StateLayerMenuSystem::DEFAULT);
}
