#include "SceneWelcome.h"

USING_NS_CC;

SceneWelcome::SceneWelcome() : _handle(nullptr)
{
}

SceneWelcome::~SceneWelcome()
{
	unscheduleUpdate();

	CC_SAFE_RELEASE_NULL(_handle);
}

bool SceneWelcome::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Scene::init());

		_handle = SceneWelcomeHandle::create();
		_handle->retain();
		_handle->setView(this);

		scheduleUpdate();

		isInit = true;
	} while (0);

	return isInit;
}

void SceneWelcome::update(float delta)
{
	_handle->update(delta);
}

void SceneWelcome::addLayer(Layer* layer)
{
	addChild(layer);
}

void SceneWelcome::removeLayer(Layer* layer)
{
	layer->removeFromParent();
}

void SceneWelcome::replaceSceneToNext(cocos2d::Scene* sceneNext, const float& duration /*= 1.0f*/)
{
	auto actionDelay = DelayTime::create(duration);
	auto acionCallFunc = CallFunc::create([sceneNext]()
	{
		sceneNext->scheduleUpdate();
	});
	sceneNext->runAction(Sequence::create(actionDelay, acionCallFunc, nullptr));

	/*auto animateScene = TransitionMoveInB::create(0.3f, scene);*/
	auto animateScene = TransitionFade::create(duration, sceneNext);
	/*auto animateScene = TransitionPageTurn::create(duration, scene, false);*/
	Director::getInstance()->replaceScene(animateScene);
}
