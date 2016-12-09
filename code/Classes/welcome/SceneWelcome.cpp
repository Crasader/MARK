#include "SceneWelcome.h"

USING_NS_CC;

SceneWelcome::SceneWelcome() : _handleWelcome(nullptr)
{
}

SceneWelcome::~SceneWelcome()
{
	unscheduleUpdate();

	CC_SAFE_RELEASE_NULL(_handleWelcome);
}

bool SceneWelcome::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Scene::init());

		_handleWelcome = HandleWelcome::create();
		_handleWelcome->retain();
		_handleWelcome->setSceneWelcome(this);

		scheduleUpdate();

		isInit = true;
	} while (0);

	return isInit;
}

void SceneWelcome::update(float delta)
{
	_handleWelcome->update(delta);
}

void SceneWelcome::addLayer(Layer* layer)
{
	addChild(layer);
}

void SceneWelcome::removeLayer(Layer* layer)
{
	layer->removeFromParent();
}
