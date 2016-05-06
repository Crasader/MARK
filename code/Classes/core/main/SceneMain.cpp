#include "SceneMain.h"
#include "../entity/LayerEntity.h"
#include "common/util/UtilRandom.h"
#include "ui/common/LayerResLoad.h"

USING_NS_CC;
USING_NS_UI_COMMON;
USING_NS_CORE_ENTITY;

SceneMain::SceneMain() : 
	_handleSceneMain(nullptr), 
	_layerResLoad(nullptr), 
	_layerEntity(nullptr), 
	_layerMenuStart(nullptr), 
	_layerMenuSystem(nullptr)
{
}

SceneMain::~SceneMain()
{
	CC_SAFE_RELEASE_NULL(_handleSceneMain);
	layerResLoadRemove();
	layerEntityRemove();
	layerMenuStartRemove();
	layerMenuSystemRemove();
}

bool SceneMain::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Scene::init());

		_handleSceneMain = HandleSceneMain::create();
		_handleSceneMain->retain();
		_handleSceneMain->setSceneMain(this);

		layerResLoadAdd();

		isInit = true;
	} while (0);

	return isInit;
}

void SceneMain::layerResLoadAdd()
{
	_layerResLoad = LayerResLoad::create();
	addChild(_layerResLoad);
}

void SceneMain::layerResLoadRemove()
{
	if (_layerResLoad)
	{
		_layerResLoad->removeFromParent();
		_layerResLoad = nullptr;
	}
}

void SceneMain::layerEntityAdd()
{
	_layerEntity = LayerEntity::create();
	addChild(_layerEntity);
}

void SceneMain::layerEntityRemove()
{
	if (_layerEntity)
	{
		_layerEntity->removeFromParent();
		_layerEntity = nullptr;
	}
}

void SceneMain::layerMenuStartAdd()
{
	_layerMenuStart = LayerMenuStart::create();
	addChild(_layerMenuStart);
}

void SceneMain::layerMenuStartRemove()
{
	if (_layerMenuStart)
	{
		_layerMenuStart->removeFromParent();
		_layerMenuStart = nullptr;
	}
}

void SceneMain::layerMenuSystemAdd()
{
	_layerMenuSystem = LayerMenuSystem::create();
	addChild(_layerMenuSystem);
}

void SceneMain::layerMenuSystemRemove()
{
	if (_layerMenuSystem)
	{
		_layerMenuSystem->removeFromParent();
		_layerMenuSystem = nullptr;
	}
}
