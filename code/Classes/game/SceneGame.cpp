#include "SceneGame.h"
#include "game/entity/LayerEntity.h"

USING_NS_CC;

SceneGame::SceneGame() : _handleGame(nullptr)
{
}

SceneGame::~SceneGame()
{
	CC_SAFE_RELEASE_NULL(_handleGame);
}

bool SceneGame::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Scene::init());

		_handleGame = HandleGame::create();
		_handleGame->retain();
		_handleGame->setSceneGame(this);

		isInit = true;
	} while (0);

	return isInit;
}

void SceneGame::update(float delta)
{
	_handleGame->update(delta);
}

void SceneGame::addLayer(cocos2d::Layer* layer)
{
	addChild(layer);
}

void SceneGame::removeLayer(cocos2d::Layer* layer)
{
	layer->removeFromParent();
}
