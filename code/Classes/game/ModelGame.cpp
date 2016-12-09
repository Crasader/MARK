#include "ModelGame.h"
#include "common/sqlite/DbHelper.h"
#include "resload/LayerResLoad.h"
#include "entity/LayerEntity.h"
#include "across/LayerAcross.h"
#include "ui/LayerMenuStart.h"
#include "ui/LayerMenuSystem.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

ModelGame::ModelGame() : 
	_listenerLayerResLoadLoaded(nullptr), 
	_state(StateGame::INIT_RODOM_SEED)
{
}

ModelGame::~ModelGame()
{
	_dicLayers.clear();
	_listenerLayerResLoadLoaded = nullptr;
}

bool ModelGame::init()
{
	auto isInit = false;

	do
	{
		isInit = true;
	} while (0);

	return isInit;
}

void ModelGame::getDatabase()
{
	auto dbHelper = DbHelper::getInstance();
	dbHelper->dataBaseOpen();
	/*dbHelper->tableCreate();*/
	dbHelper->dataBaseClose();
}

Layer* ModelGame::getLayer(const TypeLayerInGame& type)
{
	auto layer = getLayerByType(type);
	if (layer == nullptr)
	{
		layer = createLayerByType(type);
		insertLayerByType(type, layer);
	}
	return layer;
}

void ModelGame::setLayerNullptr(const TypeLayerInGame& type)
{
	eraseLayerByType(type);
}

bool ModelGame::insertLayerByType(const TypeLayerInGame& type, Layer* layer)
{
	auto layerInDic = getLayerByType(type);
	if (layerInDic != nullptr)
	{
		return false;
	}
	_dicLayers.insert(type, layer);
	return true;
}

Layer* ModelGame::createLayerByType(const TypeLayerInGame& type)
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

bool ModelGame::eraseLayerByType(const TypeLayerInGame& type)
{
	auto layer = getLayerByType(type);
	if (layer == nullptr)
	{
		return false;
	}
	_dicLayers.erase(type);
	return true;
}

Layer* ModelGame::getLayerByType(const TypeLayerInGame& type)
{
	auto layer = _dicLayers.at(type);
	return layer;
}
