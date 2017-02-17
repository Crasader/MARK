#include "SceneGame.h"
#include "game/entity/LayerEntity.h"

USING_NS_CC;

SceneGame::SceneGame() : _handle(nullptr)
{
}

SceneGame::~SceneGame()
{
	unscheduleUpdate();

	CC_SAFE_RELEASE_NULL(_handle);
}

bool SceneGame::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Scene::init());

		_handle = SceneGameHandle::create();
		_handle->retain();
		_handle->setView(this);

		isInit = true;
	} while (0);

	return isInit;
}

void SceneGame::update(float delta)
{
	_handle->update(delta);
}

void SceneGame::addLayer(cocos2d::Layer* layer)
{
	addChild(layer);
}

void SceneGame::removeLayer(cocos2d::Layer* layer)
{
	layer->removeFromParent();
}
