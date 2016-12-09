#include "HandleWelcome.h"
#include "game/SceneGame.h"
#include "common/define/DefinesValue.h"

USING_NS_CC;

HandleWelcome::HandleWelcome() : _sceneWelcome(nullptr), _modelWelcome(nullptr)
{
}

HandleWelcome::~HandleWelcome()
{
	removeEventLayerLogoOver();

	_sceneWelcome = nullptr;
	CC_SAFE_RELEASE_NULL(_modelWelcome);
}

bool HandleWelcome::init()
{
	auto isInit = false;

	do
	{
		_modelWelcome = ModelWelcome::create();
		_modelWelcome->retain();

		isInit = true;
	} while (0);

	return isInit;
}

void HandleWelcome::update(float delta)
{
	auto state = _modelWelcome->getStateWelcome();

	if (StateWelcome::DEFAULT == state)
	{
		return;
	}

	if (StateWelcome::UNPLAY_LOGO == state)
	{
		playLogo();
		return;
	}

	if (StateWelcome::PLAYING_LOGO == state)
	{
		return;
	}

	if (StateWelcome::PLAYED_LOGO == state)
	{
		playedLogo();
		return;
	}

	if (StateWelcome::REPLACE_SCENE_TO_GAME == state)
	{
		replaceSceneToGame();
		return;
	}
}

void HandleWelcome::createLayer(const TypeLayerInWelcome& type)
{
	auto layer = _modelWelcome->getLayer(type);
	_sceneWelcome->addLayer(layer);
}

void HandleWelcome::deleteLayer(const TypeLayerInWelcome& type)
{
	auto layer = _modelWelcome->getLayer(type);
	_sceneWelcome->removeLayer(layer);
	_modelWelcome->setLayerNullptr(type);
}

void HandleWelcome::playLogo()
{
	createLayer(TypeLayerInWelcome::LOGO);

	addEventLayerLogoOver();

	_modelWelcome->setStateWelcome(StateWelcome::PLAYING_LOGO);
}

void HandleWelcome::addEventLayerLogoOver()
{
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto listener = dispatcher->addCustomEventListener(EVENT_LAYER_LOGO_OVER, CC_CALLBACK_1(HandleWelcome::onEventLayerLogoOver, this));
	_modelWelcome->setListenerLayerLogoOver(listener);
}

void HandleWelcome::removeEventLayerLogoOver()
{
	auto listener = _modelWelcome->getListenerLayerLogoOver();
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->removeEventListener(listener);
}

void HandleWelcome::onEventLayerLogoOver(EventCustom* event)
{
	_modelWelcome->setStateWelcome(StateWelcome::PLAYED_LOGO);
}

void HandleWelcome::playedLogo()
{
	deleteLayer(TypeLayerInWelcome::LOGO);

	removeEventLayerLogoOver();

	_modelWelcome->setStateWelcome(StateWelcome::REPLACE_SCENE_TO_GAME);
}

void HandleWelcome::replaceSceneToGame()
{
	auto scene = SceneGame::create();

	/*auto animateScene = TransitionMoveInB::create(0.3f, scene);*/
	auto animateScene = TransitionFade::create(1.0f, scene);
	/*auto animateScene = TransitionPageTurn::create(1.0f, scene, false);*/
	Director::getInstance()->replaceScene(animateScene);

	auto actionDelay = DelayTime::create(1.0f);
	auto acionCallFunc = CallFunc::create([scene]()
	{
		scene->scheduleUpdate();
	});
	scene->runAction(Sequence::create(actionDelay, acionCallFunc, nullptr));

	_modelWelcome->setStateWelcome(StateWelcome::DEFAULT);
}
