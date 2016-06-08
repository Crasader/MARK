#include "SceneGame.h"
#include "game/entity/LayerEntity.h"
#include "common/util/UtilRandom.h"
#include "game/ui/LayerResLoad.h"

USING_NS_CC;
USING_NS_UI_COMMON;
USING_NS_GAME_ENTITY;

SceneGame::SceneGame() : 
	_handleSceneMain(nullptr), 
	_layerResLoad(nullptr), 
	_layerEntity(nullptr), 
	_layerMenuStart(nullptr), 
	_layerMenuSystem(nullptr)
{
}

SceneGame::~SceneGame()
{
	CC_SAFE_RELEASE_NULL(_handleSceneMain);
	layerResLoadRemove();
	layerEntityRemove();
	layerMenuStartRemove();
	layerMenuSystemRemove();
}

bool SceneGame::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Scene::init());

		_handleSceneMain = HandleGame::create();
		_handleSceneMain->retain();
		_handleSceneMain->setSceneGame(this);
		_handleSceneMain->crateDatabase();

		layerResLoadAdd();

		isInit = true;
	} while (0);

	return isInit;
}

void SceneGame::layerResLoadAdd()
{
	_layerResLoad = LayerResLoad::create();
	addChild(_layerResLoad);
}

void SceneGame::layerResLoadRemove()
{
	if (_layerResLoad)
	{
		_layerResLoad->removeFromParent();
		_layerResLoad = nullptr;
	}
}

void SceneGame::layerEntityAdd()
{
	_layerEntity = LayerEntity::create();
	addChild(_layerEntity);
}

void SceneGame::layerEntityRemove()
{
	if (_layerEntity)
	{
		_layerEntity->removeFromParent();
		_layerEntity = nullptr;
	}
}

void SceneGame::layerMenuStartAdd()
{
	_layerMenuStart = LayerMenuStart::create();
	addChild(_layerMenuStart);
}

void SceneGame::layerMenuStartRemove()
{
	if (_layerMenuStart)
	{
		_layerMenuStart->removeFromParent();
		_layerMenuStart = nullptr;
	}
}

void SceneGame::layerMenuSystemAdd()
{
	_layerMenuSystem = LayerMenuSystem::create();
	addChild(_layerMenuSystem);
}

void SceneGame::layerMenuSystemRemove()
{
	if (_layerMenuSystem)
	{
		_layerMenuSystem->removeFromParent();
		_layerMenuSystem = nullptr;
	}
}
