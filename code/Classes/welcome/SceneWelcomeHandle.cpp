#include "SceneWelcome.h"
#include "common/define/DefinesValue.h"

USING_NS_CC;

SceneWelcomeHandle::SceneWelcomeHandle() : 
	_view(nullptr), 
	_model(nullptr)
{
}

SceneWelcomeHandle::~SceneWelcomeHandle()
{
	removeEventLayerLogoOver();

	_view = nullptr;
	CC_SAFE_RELEASE_NULL(_model);
}

bool SceneWelcomeHandle::init()
{
	auto isInit = false;

	do
	{
		_model = SceneWelcomeModel::create();
		_model->retain();

		attachStateCallback();

		isInit = true;
	} while (0);

	return isInit;
}

void SceneWelcomeHandle::attachStateCallback()
{
	auto& stateCallback = _model->getStateCallback();
	stateCallback.insertCallback(StateWelcome::DEFAULT, nullptr);
	stateCallback.insertCallback(StateWelcome::UNPLAY_LOGO, CC_CALLBACK_0(SceneWelcomeHandle::playLogo, this));
	stateCallback.insertCallback(StateWelcome::PLAYED_LOGO, CC_CALLBACK_0(SceneWelcomeHandle::playedLogo, this), CC_CALLBACK_1(SceneWelcomeHandle::playedLogoCheck, this));
	stateCallback.insertCallback(StateWelcome::REPLACE_SCENE, CC_CALLBACK_0(SceneWelcomeHandle::replaceScene, this));
}

void SceneWelcomeHandle::update(float delta)
{
	auto& stateCallback = _model->getStateCallback();
	stateCallback.doCallbackByCurrentState(delta);
}

void SceneWelcomeHandle::createLayer(const TypeLayerInWelcome& type)
{
	auto layer = _model->getLayer(type);
	_view->addLayer(layer);
}

void SceneWelcomeHandle::deleteLayer(const TypeLayerInWelcome& type)
{
	auto layer = _model->getLayer(type);
	_view->removeLayer(layer);
	_model->setLayerNullptr(type);
}

void SceneWelcomeHandle::playLogo()
{
	createLayer(TypeLayerInWelcome::LOGO);

	addEventLayerLogoOver();

	_model->setState(StateWelcome::PLAYED_LOGO);
}

void SceneWelcomeHandle::addEventLayerLogoOver()
{
	_model->addEventListenerLogoOver(CC_CALLBACK_1(SceneWelcomeHandle::onEventLayerLogoOver, this));
}

void SceneWelcomeHandle::removeEventLayerLogoOver()
{
	_model->removeEventLIstenerLogoOver();
}

void SceneWelcomeHandle::onEventLayerLogoOver(EventCustom* event)
{
	_model->setIsLogoPlayOver(true);
}

bool SceneWelcomeHandle::playedLogoCheck(float delta)
{
	auto isLogoPlayOver = _model->getIsLogoPlayOver();
	return isLogoPlayOver;
}

void SceneWelcomeHandle::playedLogo()
{
	deleteLayer(TypeLayerInWelcome::LOGO);

	removeEventLayerLogoOver();

	_model->setState(StateWelcome::REPLACE_SCENE);
}

void SceneWelcomeHandle::replaceScene()
{
	_view->replaceSceneToGame();
	_model->setState(StateWelcome::DEFAULT);
}
