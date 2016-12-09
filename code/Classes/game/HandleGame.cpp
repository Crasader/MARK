#include "HandleGame.h"
#include "common/util/UtilRandom.h"
#include "common/define/DefinesValue.h"
#include "ManagerHandle.h"

USING_NS_CC;

HandleGame::HandleGame() : _sceneGame(nullptr), _modelGame(nullptr)
{
}

HandleGame::~HandleGame()
{
	removeEventLayerResLoadLoaded();

	ManagerHandle::getInstance()->detach(this);
	
	_sceneGame = nullptr;
	CC_SAFE_RELEASE_NULL(_modelGame);
}

bool HandleGame::init()
{
	auto isInit = false;

	do
	{
		_modelGame = ModelGame::create();
		_modelGame->retain();

		isInit = true;
	} while (0);

	return isInit;
}

void HandleGame::update(float delta)
{
	auto state = _modelGame->getStateGame();

	if (StateGame::DEFAULT == state)
	{
		return;
	}

	if (StateGame::INIT_RODOM_SEED == state)
	{
		initRandomSeed();
		return;
	}

	if (StateGame::ATTACH_OBSERVER == state)
	{
		attachOvserver();
		return;
	}

	if (StateGame::GET_DATA_BASE == state)
	{
		getDatabase();
		return;
	}

	if (StateGame::UNLOAD_RES == state)
	{
		loadRes();
		return;
	}

	if (StateGame::LOADING_RES == state)
	{
		return;
	}

	if (StateGame::LOADED_RES == state)
	{
		loadedRes();
		return;
	}
}

void HandleGame::updateBySubject(va_list values)
{
	auto type = va_arg(values, TO_HANDLE_SCENE_GAME);
	switch (type)
	{
	case TO_HANDLE_SCENE_GAME::LAYER_RES_LOAD_ADD:
		createLayer(TypeLayerInGame::RESLOAD);
		break;
	case TO_HANDLE_SCENE_GAME::LAYER_RES_LOAD_REMOVE:
		deleteLayer(TypeLayerInGame::RESLOAD);
		break;
	case TO_HANDLE_SCENE_GAME::LAYER_ENTITY_ADD:
		createLayer(TypeLayerInGame::ENTITY);
		break;
	case TO_HANDLE_SCENE_GAME::LAYER_ENTITY_REMOVE:
		deleteLayer(TypeLayerInGame::ENTITY);
		break;
	case TO_HANDLE_SCENE_GAME::LAYER_MENU_START_ADD:
		createLayer(TypeLayerInGame::MENU_START);
		break;
	case TO_HANDLE_SCENE_GAME::LAYER_MENU_START_REMOVE:
		deleteLayer(TypeLayerInGame::MENU_START);
		break;
	case TO_HANDLE_SCENE_GAME::LAYER_MENU_SYSTEM_ADD:
		createLayer(TypeLayerInGame::MENU_SYSTEM);
		break;
	case TO_HANDLE_SCENE_GAME::LAYER_MENU_SYSTEM_REMOVE:
		deleteLayer(TypeLayerInGame::MENU_SYSTEM);
		break;
	default:
		break;
	}
}

void HandleGame::initRandomSeed()
{
	UtilRandom::initRandomSeed();
	_modelGame->setStateGame(StateGame::ATTACH_OBSERVER);
}

void HandleGame::attachOvserver()
{
	idObserverSet((int)ID_OBSERVER::HANDLE_SCENE_GAME);
	ManagerHandle::getInstance()->attach(this);
	_modelGame->setStateGame(StateGame::GET_DATA_BASE);
}

void HandleGame::getDatabase()
{
	_modelGame->getDatabase();
	_modelGame->setStateGame(StateGame::UNLOAD_RES);
}

void HandleGame::createLayer(const TypeLayerInGame& type)
{
	auto layer = _modelGame->getLayer(type);
	_sceneGame->addLayer(layer);
}

void HandleGame::deleteLayer(const TypeLayerInGame& type)
{
	auto layer = _modelGame->getLayer(type);
	_sceneGame->removeLayer(layer);
	_modelGame->setLayerNullptr(type);
}

void HandleGame::loadRes()
{
	createLayer(TypeLayerInGame::RESLOAD);

	addEventLayerResLoadLoaded();

	_modelGame->setStateGame(StateGame::LOADING_RES);
}

void HandleGame::addEventLayerResLoadLoaded()
{
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto listener = dispatcher->addCustomEventListener(EVENT_LAYER_RES_LOAD_LOADED, CC_CALLBACK_1(HandleGame::onEventLayerResLoadLoaded, this));
	_modelGame->setListenerLayerResLoadLoaded(listener);
}

void HandleGame::removeEventLayerResLoadLoaded()
{
	auto listener = _modelGame->getListenerLayerResLoadLoaded();
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->removeEventListener(listener);
}

void HandleGame::onEventLayerResLoadLoaded(cocos2d::EventCustom* event)
{
	_modelGame->setStateGame(StateGame::LOADED_RES);
}

void HandleGame::loadedRes()
{
	deleteLayer(TypeLayerInGame::RESLOAD);
	createLayer(TypeLayerInGame::ENTITY);
	createLayer(TypeLayerInGame::MENU_START);

	removeEventLayerResLoadLoaded();

	_modelGame->setStateGame(StateGame::DEFAULT);
}
