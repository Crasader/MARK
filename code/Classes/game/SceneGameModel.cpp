#include "SceneGame.h"
#include "common/sqlite/DbHelper.h"
#include "resload/LayerResLoad.h"
#include "entity/LayerEntity.h"
#include "across/LayerAcross.h"
#include "ui/LayerMenuStart.h"
#include "ui/LayerMenuSystem.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

SceneGameModel::SceneGameModel() : 
	_stateCallback(),
	_isLoadedRes(false),
	_dicLayers(),
	_listener(nullptr)
{
	setState(StateGame::INIT_RODOM_SEED);
}

SceneGameModel::~SceneGameModel()
{
	_listener = nullptr;
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

void SceneGameModel::setLayerAcrossNumSize(const int& numRow, const int& numColumn, const cocos2d::Size& size, const bool& isTest/* = false*/)
{
	auto layerAcross = (LayerAcross*)getLayer(TypeLayerInGame::ACROSS);
	if (layerAcross)
	{
		auto model = layerAcross->getHandle()->getModel();
		model->setAcrossObjectNumSize(numRow, numColumn, size);
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
	case TypeLayerInGame::MENU_START:
		return LayerMenuStart::create();
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
