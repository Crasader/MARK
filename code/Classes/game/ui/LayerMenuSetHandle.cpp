#include "LayerMenuSet.h"
#include "defines/DefinesString.h"
#include <vector>
#include <string>
#include "game/ManagerHandle.h"
#include "defines/DefinesValue.h"

USING_NS_CC;
using namespace ui;

LayerMenuSetHandle::LayerMenuSetHandle() : _view(nullptr), _model(nullptr)
{
}

LayerMenuSetHandle::~LayerMenuSetHandle()
{
	_model = nullptr;
	_view = nullptr;
}

bool LayerMenuSetHandle::init()
{
	auto isInit = false;

	do 
	{
		_model = LayerMenuSetModel::create();
		_model->retain();

		attachStateCallback();

		isInit = true;
	} while (0);

	return isInit;
}

void LayerMenuSetHandle::attachStateCallback()
{
	auto& stateCallback = _model->getStateCallback();
	stateCallback.insertCallback(StateLayerMenuSet::DEFAULT);
	stateCallback.insertCallback(StateLayerMenuSet::CREATE_SKIN, CC_CALLBACK_0(LayerMenuSetHandle::createSkin, this));
	stateCallback.insertCallback(StateLayerMenuSet::ADD_EVENT, CC_CALLBACK_0(LayerMenuSetHandle::addEvent, this));
	stateCallback.insertCallback(StateLayerMenuSet::PLAY_ANIMATION, CC_CALLBACK_0(LayerMenuSetHandle::playAnimation, this));
}

void LayerMenuSetHandle::update(float delta)
{
	auto& stateCallback = _model->getStateCallback();
	stateCallback.doCallbackByCurrentState(delta);
}

void LayerMenuSetHandle::createSkin()
{
	auto skin = _model->getSkin();
	_view->addLayer(skin);

	_model->setState(StateLayerMenuSet::ADD_EVENT);
}

void LayerMenuSetHandle::addEvent()
{
	std::vector<std::string> vecNames = { STR_MENU_CONTINUE, STR_MENU_SAVE_LOAD, STR_MENU_SETTING };
	std::vector<std::function<void(Ref* ref, Widget::TouchEventType type)>> vecOnTouchs =
	{
		CC_CALLBACK_2(LayerMenuSetHandle::onTouchBtnContinue, this),
		CC_CALLBACK_2(LayerMenuSetHandle::onTouchBtnSaveLoad, this),
		CC_CALLBACK_2(LayerMenuSetHandle::onTouchBtnSetting, this)
	};
	auto& vecBtns = _model->getVecBtns();
	auto length = vecBtns.size();
	for (auto i = 0; i < length; i++)
	{
		auto btn = vecBtns.at(i);
		_view->addEvent(btn, vecNames.at(i), vecOnTouchs.at(i));
	}

	_model->setState(StateLayerMenuSet::PLAY_ANIMATION);
}

void LayerMenuSetHandle::onTouchBtnContinue(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::ENDED)
	{
		auto btn = (Button*)ref;
		/*auto manager = ManagerHandle::getInstance();
		manager->notify((int)ID_OBSERVER::HANDLE_LAYER_ENTITY, TO_HANDLE_LAYER_ENTITY::GAME_START);
		manager->notify((int)ID_OBSERVER::HANDLE_SCENE_GAME, TO_HANDLE_SCENE_GAME::LAYER_MENU_START_REMOVE);
		manager->notify((int)ID_OBSERVER::HANDLE_SCENE_GAME, TO_HANDLE_SCENE_GAME::LAYER_ACROSS_ADD);*/
	}
}

void LayerMenuSetHandle::onTouchBtnSaveLoad(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::ENDED)
	{
		auto btn = (Button*)ref;
	}
}

void LayerMenuSetHandle::onTouchBtnSetting(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::ENDED)
	{
		auto btn = (Button*)ref;
	}
}

void LayerMenuSetHandle::playAnimation()
{
	auto skin = _model->getSkin();
	auto action = _model->getAnimation();
	_view->playAnimation(skin, action);

	_model->setState(StateLayerMenuSet::DEFAULT);
}
