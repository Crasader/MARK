#include "SceneGame.h"
#include "common/util/UtilRandom.h"
#include "common/define/DefinesValue.h"
#include "ManagerHandle.h"

USING_NS_CC;

SceneGameHandle::SceneGameHandle() : 
	_view(nullptr), 
	_model(nullptr)
{
}

SceneGameHandle::~SceneGameHandle()
{
	removeEventLayerResLoadLoaded();

	ManagerHandle::getInstance()->detach(this);
	
	_view = nullptr;
	CC_SAFE_RELEASE_NULL(_model);
}

bool SceneGameHandle::init()
{
	auto isInit = false;

	do
	{
		_model = SceneGameModel::create();
		_model->retain();

		attachStateCallback();

		isInit = true;
	} while (0);

	return isInit;
}

void SceneGameHandle::attachStateCallback()
{
	auto& stateCallback = _model->getStateCallback();
	stateCallback.insertCallback(StateGame::DEFAULT);
	stateCallback.insertCallback(StateGame::INIT_RODOM_SEED, CC_CALLBACK_0(SceneGameHandle::initRandomSeed, this));
	stateCallback.insertCallback(StateGame::ATTACH_OBSERVER, CC_CALLBACK_0(SceneGameHandle::attachOvserver, this));
	stateCallback.insertCallback(StateGame::DEAL_DATA_BASE, CC_CALLBACK_0(SceneGameHandle::dealDatabase, this));
	stateCallback.insertCallback(StateGame::UNLOAD_RES, CC_CALLBACK_0(SceneGameHandle::loadRes, this));
	stateCallback.insertCallback(StateGame::LOADED_RES, CC_CALLBACK_0(SceneGameHandle::loadedRes, this), CC_CALLBACK_1(SceneGameHandle::loadedResCheck, this));
	stateCallback.insertCallback(StateGame::CREATE_ENTITY, CC_CALLBACK_0(SceneGameHandle::createEntity, this));
	stateCallback.insertCallback(StateGame::CREATED_ENTITY, CC_CALLBACK_0(SceneGameHandle::createdEntity, this), CC_CALLBACK_1(SceneGameHandle::createdEntityCheck, this));
	stateCallback.insertCallback(StateGame::CREATE_MENU_SYSTEM, CC_CALLBACK_0(SceneGameHandle::createMenuSystem, this));
	stateCallback.insertCallback(StateGame::CREATED_MENU_SYSTEM, CC_CALLBACK_0(SceneGameHandle::createdMenuSystem, this), CC_CALLBACK_1(SceneGameHandle::createdMenuSystemCheck, this));
}

void SceneGameHandle::update(float delta)
{
	auto& stateCallback = _model->getStateCallback();
	stateCallback.doCallbackByCurrentState(delta);
}

void SceneGameHandle::initRandomSeed()
{
	UtilRandom::initRandomSeed();
	_model->setState(StateGame::ATTACH_OBSERVER);
}

void SceneGameHandle::attachOvserver()
{
	idObserverSet((int)ID_OBSERVER::HANDLE_SCENE_GAME);
	ManagerHandle::getInstance()->attach(this);
	_model->setState(StateGame::DEAL_DATA_BASE);
}

void SceneGameHandle::dealDatabase()
{
	_model->dealDatabase();
	_model->setState(StateGame::UNLOAD_RES);
}

void SceneGameHandle::loadRes()
{
	createLayer(TypeLayerInGame::RESLOAD);

	addEventLayerResLoadLoaded();

	_model->setState(StateGame::LOADED_RES);
}

void SceneGameHandle::addEventLayerResLoadLoaded()
{
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto listener = dispatcher->addCustomEventListener(EVENT_LAYER_RES_LOAD_LOADED, CC_CALLBACK_1(SceneGameHandle::onEventLayerResLoadLoaded, this));
	_model->setListenerLayerResLoadLoaded(listener);
}

void SceneGameHandle::removeEventLayerResLoadLoaded()
{
	auto listener = _model->getListenerLayerResLoadLoaded();
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->removeEventListener(listener);
}

void SceneGameHandle::onEventLayerResLoadLoaded(cocos2d::EventCustom* event)
{
	_model->setIsLoadedRes(true);
}

bool SceneGameHandle::loadedResCheck(float delta)
{
	auto isLoadedRes = _model->getIsLoadedRes();
	return isLoadedRes;
}

void SceneGameHandle::loadedRes()
{
	deleteLayer(TypeLayerInGame::RESLOAD);
	
	removeEventLayerResLoadLoaded();

	_model->setState(StateGame::CREATE_ENTITY);
}

void SceneGameHandle::createEntity()
{
	createLayer(TypeLayerInGame::ENTITY);

	_model->setState(StateGame::CREATED_ENTITY);
}

bool SceneGameHandle::createdEntityCheck(float delta)
{
	auto isCreatedEntity = _model->getIsCreatedEntity();
	return isCreatedEntity;
}

void SceneGameHandle::createdEntity()
{
	_model->setState(StateGame::CREATE_MENU_SYSTEM);
}

void SceneGameHandle::createMenuSystem()
{
	createLayer(TypeLayerInGame::MENU_SYSTEM);

	_model->setState(StateGame::CREATED_MENU_SYSTEM);
}

bool SceneGameHandle::createdMenuSystemCheck(float delta)
{
	auto isTimeOver = _model->isMenuSystemAnimationPlayOver();
	return isTimeOver;
}

void SceneGameHandle::createdMenuSystem()
{
	_model->setState(StateGame::DEFAULT);
}

void SceneGameHandle::updateBySubject(va_list values)
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
	case TO_HANDLE_SCENE_GAME::LAYER_MENU_SET_ADD:
		createLayer(TypeLayerInGame::MENU_SET);
		break;
	case TO_HANDLE_SCENE_GAME::LAYER_MENU_SET_REMOVE:
		deleteLayer(TypeLayerInGame::MENU_SET);
		break;
	case TO_HANDLE_SCENE_GAME::LAYER_MENU_SET_SWITCH:
		switchLayer(TypeLayerInGame::MENU_SET);
		break;
	case TO_HANDLE_SCENE_GAME::LAYER_MENU_SYSTEM_ADD:
		createLayer(TypeLayerInGame::MENU_SYSTEM);
		break;
	case TO_HANDLE_SCENE_GAME::LAYER_MENU_SYSTEM_REMOVE:
		deleteLayer(TypeLayerInGame::MENU_SYSTEM);
		break;
	case TO_HANDLE_SCENE_GAME::LAYER_ACROSS_ADD:
		createLayer(TypeLayerInGame::ACROSS, CC_CALLBACK_0(SceneGameHandle::extraFuncCreateLayerAcross, this));
		break;
	case TO_HANDLE_SCENE_GAME::LAYER_ACROSS_REMOVE:
		deleteLayer(TypeLayerInGame::ACROSS);
		break;
	default:
		break;
	}
}

void SceneGameHandle::createLayer(const TypeLayerInGame& type, const std::function<void()>& extraFunc /*= nullptr*/)
{
	auto layer = _model->getLayer(type);
	_view->addLayer(layer);

	if (extraFunc != nullptr)
	{
		extraFunc();
	}
}

void SceneGameHandle::deleteLayer(const TypeLayerInGame& type, const std::function<void()>& extraFunc /*= nullptr*/)
{
	if (extraFunc != nullptr)
	{
		extraFunc();
	}

	auto layer = _model->getLayer(type);
	_view->removeLayer(layer);
	_model->setLayerNullptr(type);
}

void SceneGameHandle::switchLayer(const TypeLayerInGame& type, const std::function<void()>& extraFunc /*= nullptr*/)
{
	auto layer = _model->getLayer(type);
	if (layer->getParent() == nullptr)
	{
		createLayer(type, extraFunc);
	}
	else
	{
		deleteLayer(type, extraFunc);
	}
}
void SceneGameHandle::extraFuncCreateLayerAcross(/*va_list values*/)
{
	auto postionX = 320.0f/*(float)va_arg(values, double)*/;
	auto postionY = 480.0f/*(float)va_arg(values, double)*/;
	auto numRow = 3/*va_arg(values, int)*/;
	auto numColumn = 3/*va_arg(values, int)*/;
	auto sizeWidth = 100.0f/*(float)va_arg(values, double)*/;
	auto sizeHeight = 100.0f/*(float)va_arg(values, double)*/;

	_model->setLayerPostion(TypeLayerInGame::ACROSS, Vec2(postionX, postionY));
	_model->setLayerAcrossNumSize(numRow, numColumn, Size(sizeWidth, sizeHeight), true);
}
