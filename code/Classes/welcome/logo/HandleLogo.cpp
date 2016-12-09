#include "HandleLogo.h"
#include "common/define/DefinesValue.h"

USING_NS_CC;

HandleLogo::HandleLogo() : _layerLogo(nullptr), _modelLogo(nullptr)
{
}

HandleLogo::~HandleLogo()
{
	_layerLogo = nullptr;
	CC_SAFE_RELEASE_NULL(_modelLogo);
}

bool HandleLogo::init()
{
	auto isInit = false;

	do
	{
		_modelLogo = ModelLogo::create();
		_modelLogo->retain();

		isInit = true;
	} while (0);

	return isInit;
}

void HandleLogo::update(float delta)
{
	auto state = _modelLogo->getState();
	
	if (StateLogo::DEFLATE == state)
	{
		return;
	}

	if (StateLogo::CREATE_SKIN == state)
	{
		createSkin();
		return;
	}

	if (StateLogo::UNPLAY_LOGO == state)
	{
		playLogo();
		return;
	}

	if (StateLogo::PLAYING_LOGO == state)
	{
		playingLogo(delta);
		return;
	}

	if (StateLogo::PLAYED_LOGO == state)
	{
		playedLogo();
		return;
	}
}

void HandleLogo::createSkin()
{
	auto _skin = _modelLogo->getSkin();
	_layerLogo->addSkin(_skin);

	_modelLogo->setState(StateLogo::UNPLAY_LOGO);
}

void HandleLogo::playLogo()
{
	auto _skin = _modelLogo->getSkin();
	auto action = _modelLogo->getAnimation(LAYER_LOGO_ANIMATION_0, false);
	_layerLogo->playAnimation(_skin, action);

	_modelLogo->setState(StateLogo::PLAYING_LOGO);
}

void HandleLogo::playingLogo(float delta)
{
	_modelLogo->addDuration(delta);
	auto isTimeOver = _modelLogo->isTimeOver();
	if (isTimeOver)
	{
		_modelLogo->setState(StateLogo::PLAYED_LOGO);
	}
}

void HandleLogo::playedLogo()
{
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->dispatchCustomEvent(EVENT_LAYER_LOGO_OVER);

	_modelLogo->setState(StateLogo::DEFLATE);
}
