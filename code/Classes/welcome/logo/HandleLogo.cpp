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
	
	if (StateLogo::SKIN_UNCREATE == state)
	{
		_layerLogo->createSkin();
		_modelLogo->setState(StateLogo::SKIN_CREATED);
		return;
	}

	if (StateLogo::SKIN_CREATED == state)
	{
		_layerLogo->playAnimation();
		_modelLogo->setState(StateLogo::LOGOPLAYING);
		return;
	}

	if (StateLogo::LOGOPLAYING == state)
	{
		_modelLogo->addDuration(delta);
		auto isTimeOver = _modelLogo->isTimeOver();
		if (isTimeOver)
		{
			_modelLogo->setState(StateLogo::LOGOOVER);
			Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_LAYER_LOGO_OVER);
		}
		return;
	}

	if (StateLogo::LOGOOVER == state)
	{

		return;
	}
}

bool HandleLogo::isStateLogoBeLogoOver()
{
	return StateLogo::LOGOOVER == _modelLogo->getState();
}
