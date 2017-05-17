#include "SceneGame.h"
#include "common/sqlite/DbHelper.h"
#include "resload/LayerResLoad.h"
#include "entity/LayerEntity.h"
#include "across/LayerAcross.h"
#include "ui/LayerMenuSet.h"
#include "ui/LayerMenuSystem.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

SceneGameModel::SceneGameModel() : 
	_stateCallback(StateGame::INIT_RODOM_SEED),
	_isLoadedRes(false),
	_dicLayers(),
	_listenerResLoaded(nullptr)
{
}

SceneGameModel::~SceneGameModel()
{
	_listenerResLoaded = nullptr;
	_dicLayers.clear();
	_isLoadedRes = false;
	_stateCallback.clearDic();
}

bool SceneGameModel::init()
{
	auto isInit = false;

	do
	{
		isInit = true;
	} while (0);

	return isInit;
}

void SceneGameModel::dealDatabase()
{
	auto dbHelper = DbHelper::getInstance();
	dbHelper->dataBaseOpen();
	/*dbHelper->tableCreate();*/
	dbHelper->dataBaseClose();
}

Layer* SceneGameModel::getLayer(const TypeLayerInGame& type)
{
	auto layer = getLayerByType(type);
	if (layer == nullptr)
	{
		layer = createLayerByType(type);
		insertLayerByType(type, layer);
	}
	return layer;
}

void SceneGameModel::setLayerPostion(const TypeLayerInGame& type, const cocos2d::Vec2& postion)
{
	auto layer = getLayerByType(type);
	if (layer != nullptr)
	{
		layer->setPosition(postion);
	}
}

void SceneGameModel::setLayerNullptr(const TypeLayerInGame& type)
{
	eraseLayerByType(type);
}

void SceneGameModel::setLayerAcrossNumSize(const int& numRow, const int& numColumn, const cocos2d::Size& size, const float& rowInterval /*= 1.0f*/, const float& columnInterval /*= 1.0f*/, const bool& isTest /*= false*/)
{
	auto layerAcross = (LayerAcross*)getLayer(TypeLayerInGame::ACROSS);
	if (layerAcross)
	{
		auto model = layerAcross->getHandle()->getModel();
		model->setAcrossObjectNumSize(numRow, numColumn, size, rowInterval, columnInterval);
		model->setTest(isTest);
	}
}

Layer* SceneGameModel::createLayerByType(const TypeLayerInGame& type)
{
	switch (type)
	{
	case TypeLayerInGame::RESLOAD:
		return LayerResLoad::create();
	case TypeLayerInGame::ENTITY:
		return LayerEntity::create();
	case TypeLayerInGame::ACROSS:
		return LayerAcross::create();
	case TypeLayerInGame::MENU_SET:
		return LayerMenuSet::create();
	case TypeLayerInGame::MENU_SYSTEM:
		return LayerMenuSystem::create();
	default:
		return nullptr;
	}
}

bool SceneGameModel::insertLayerByType(const TypeLayerInGame& type, Layer* layer)
{
	auto layerInDic = getLayerByType(type);
	if (layerInDic != nullptr)
	{
		return false;
	}
	_dicLayers.insert(type, layer);
	return true;
}

bool SceneGameModel::eraseLayerByType(const TypeLayerInGame& type)
{
	auto layer = getLayerByType(type);
	if (layer == nullptr)
	{
		return false;
	}
	_dicLayers.erase(type);
	return true;
}

Layer* SceneGameModel::getLayerByType(const TypeLayerInGame& type)
{
	auto layer = _dicLayers.at(type);
	return layer;
}

void SceneGameModel::addEventListenerResLoaded(const std::function<void(cocos2d::EventCustom*)>& callback)
{
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	_listenerResLoaded = dispatcher->addCustomEventListener(EVENT_LAYER_RES_LOAD_LOADED, callback);
}

void SceneGameModel::removeEventListenerResLoaded()
{
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->removeEventListener(_listenerResLoaded);
}

bool SceneGameModel::isMenuSystemAnimationPlayOver()
{
	auto layer = (LayerMenuSystem*)getLayerByType(TypeLayerInGame::MENU_SYSTEM);
	if (layer == nullptr)
	{
		return false;
	}
	auto isOver = layer->getHandle()->getModel()->getAnimationPlayOver();
	return isOver;
}
