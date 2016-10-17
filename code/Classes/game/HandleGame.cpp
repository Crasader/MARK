#include "HandleGame.h"
#include "common/util/UtilRandom.h"
#include "common/define/DefinesValue.h"
#include "ManagerHandle.h"

USING_NS_CC;

HandleGame::HandleGame() : _sceneMain(nullptr), _modelGame(nullptr)
{
}

HandleGame::~HandleGame()
{
	auto listener = _modelGame->getListener();
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->removeEventListener(listener);

	ManagerHandle::getInstance()->detach(this);
	
	_sceneMain = nullptr;
	CC_SAFE_RELEASE_NULL(_modelGame);
}

bool HandleGame::init()
{
	auto isInit = false;

	do
	{
		UtilRandom::initRandomSeed();

		idObserverSet((int)ID_OBSERVER::HANDLE_SCENE_MAIN);
		ManagerHandle::getInstance()->attach(this);

		_modelGame = ModelGame::create();
		_modelGame->retain();

		auto dispatcher = Director::getInstance()->getEventDispatcher();
		auto listener = dispatcher->addCustomEventListener(EVENT_LAYER_RES_LOAD_LOADED, CC_CALLBACK_1(HandleGame::onEventLayerResLoadLoaded, this));
		_modelGame->setListener(listener);

		isInit = true;
	} while (0);

	return isInit;
}

void HandleGame::updateBySubject(va_list values)
{
	auto type = va_arg(values, TO_HANDLE_SCENE_MAIN);
	switch (type)
	{
	case TO_HANDLE_SCENE_MAIN::LAYER_RES_LOAD_ADD:
		_sceneMain->layerResLoadAdd();
		break;
	case TO_HANDLE_SCENE_MAIN::LAYER_RES_LOAD_REMOVE:
		_sceneMain->layerResLoadRemove();
		break;
	case TO_HANDLE_SCENE_MAIN::LAYER_ENTITY_ADD:
		_sceneMain->layerEntityAdd();
		break;
	case TO_HANDLE_SCENE_MAIN::LAYER_ENTITY_REMOVE:
		_sceneMain->layerEntityRemove();
		break;
	case TO_HANDLE_SCENE_MAIN::LAYER_MENU_START_ADD:
		_sceneMain->layerMenuStartAdd();
		break;
	case TO_HANDLE_SCENE_MAIN::LAYER_MENU_START_REMOVE:
		_sceneMain->layerMenuStartRemove();
		break;
	case TO_HANDLE_SCENE_MAIN::LAYER_MENU_SYSTEM_ADD:
		_sceneMain->layerMenuSystemAdd();
		break;
	case TO_HANDLE_SCENE_MAIN::LAYER_MENU_SYSTEM_REMOVE:
		_sceneMain->layerMenuSystemRemove();
		break;
	default:
		break;
	}
}

void HandleGame::onEventLayerResLoadLoaded(cocos2d::EventCustom* event)
{
	_sceneMain->layerResLoadRemove();
	_sceneMain->layerEntityAdd();
	_sceneMain->layerMenuStartAdd();
	_sceneMain->layerMenuSystemAdd();
}

void HandleGame::crateDatabase()
{
	_modelGame->createDatabase();
}
