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

		addEventLayerLogoOver();

		isInit = true;
	} while (0);

	return isInit;
}

void HandleWelcome::addEventLayerLogoOver()
{
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto listener = dispatcher->addCustomEventListener(EVENT_LAYER_LOGO_OVER, CC_CALLBACK_1(HandleWelcome::onEventLayerLogoOver, this));
	_modelWelcome->setEventListener(listener);
}

void HandleWelcome::removeEventLayerLogoOver()
{
	auto listener = _modelWelcome->getEventListener();
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->removeEventListener(listener);
}

void HandleWelcome::onEventLayerLogoOver(EventCustom* event)
{
	replaceSceneToGame();
	removeEventLayerLogoOver();
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
}
