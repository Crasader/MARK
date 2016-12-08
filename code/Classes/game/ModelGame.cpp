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

Layer* ModelGame::getLayer(const TypeLayer& type)
{
	auto layer = getLayerByType(type);
	if (layer == nullptr)
	{
		layer = createLayerByType(type);
		insertLayerByType(type, layer);
	}
	return layer;
}

void ModelGame::setLayerNullptr(const TypeLayer& type)
{
	eraseLayerByType(type);
}

bool ModelGame::insertLayerByType(const TypeLayer& type, Layer* layer)
{
	auto layerInDic = getLayerByType(type);
	if (layerInDic != nullptr)
	{
		return false;
	}
	_dicLayers.insert(type, layer);
	return true;
}

Layer* ModelGame::createLayerByType(const TypeLayer& type)
{
	switch (type)
	{
	case TypeLayer::RESLOAD:
		return LayerResLoad::create();
	case TypeLayer::ENTITY:
		return LayerEntity::create();
	case TypeLayer::ACROSS:
		return LayerAcross::create();
	case TypeLayer::MENU_START:
		return LayerMenuStart::create();
	case TypeLayer::MENU_SYSTEM:
		return LayerMenuSystem::create();
	default:
		return nullptr;
	}
}

bool ModelGame::eraseLayerByType(const TypeLayer& type)
{
	auto layer = getLayerByType(type);
	if (layer == nullptr)
	{
		return false;
	}
	_dicLayers.erase(type);
	return true;
}

Layer* ModelGame::getLayerByType(const TypeLayer& type)
{
	auto layer = _dicLayers.at(type);
	return layer;
}
