#include "LayerLogo.h"
#include "defines/DefinesValue.h"

USING_NS_CC;

LayerLogoHandle::LayerLogoHandle() : 
	_view(nullptr), 
	_model(nullptr)
{
}

LayerLogoHandle::~LayerLogoHandle()
{
	_view = nullptr;
	CC_SAFE_RELEASE_NULL(_model);
}

bool LayerLogoHandle::init()
{
	auto isInit = false;

	do
	{
		_model = LayerLogoModel::create();
		_model->retain();

		attachStateCallback();

		isInit = true;
	} while (0);

	return isInit;
}

void LayerLogoHandle::attachStateCallback()
{
	auto& stateCallback = _model->getStateCallback();
	stateCallback.insertCallback(StateLayerLogo::DEFAULT, nullptr);
	stateCallback.insertCallback(StateLayerLogo::CREATE_SKIN, CC_CALLBACK_0(LayerLogoHandle::createSkin, this));
	stateCallback.insertCallback(StateLayerLogo::UNPLAY_LOGO, CC_CALLBACK_0(LayerLogoHandle::playLogo, this));
	stateCallback.insertCallback(StateLayerLogo::PLAYING_LOGO, CC_CALLBACK_0(LayerLogoHandle::playingLogo, this), CC_CALLBACK_1(LayerLogoHandle::playingLogoCheck, this));
	stateCallback.insertCallback(StateLayerLogo::PLAYED_LOGO, CC_CALLBACK_0(LayerLogoHandle::playedLogo, this));
}

void LayerLogoHandle::update(float delta)
{
	auto& stateCallback = _model->getStateCallback();
	stateCallback.doCallbackByCurrentState(delta);
}

void LayerLogoHandle::createSkin()
{
	auto _skin = _model->getSkin();
	_view->addSkin(_skin);

	_model->setState(StateLayerLogo::UNPLAY_LOGO);
}

void LayerLogoHandle::playLogo()
{
	auto _skin = _model->getSkin();
	auto action = _model->getActionTimeline();
	_view->playAnimation(_skin, action, LAYER_LOGO_ANIMATION_0, false);

	_model->setState(StateLayerLogo::PLAYING_LOGO);
}

bool LayerLogoHandle::playingLogoCheck(float delta)
{
	_model->addDuration(delta);
	auto isTimeOver = _model->isTimeOver();
	return isTimeOver;
}

void LayerLogoHandle::playingLogo()
{
	_model->setState(StateLayerLogo::PLAYED_LOGO);
}

void LayerLogoHandle::playedLogo()
{
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->dispatchCustomEvent(EVENT_LAYER_LOGO_OVER);

	_model->setState(StateLayerLogo::DEFAULT);
}
