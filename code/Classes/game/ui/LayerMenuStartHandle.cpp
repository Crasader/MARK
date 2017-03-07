#include "LayerMenuStart.h"
#include "game/ManagerHandle.h"
#include "common/define/DefinesValue.h"

LayerMenuStartHandle::LayerMenuStartHandle() : _layerMenuStart(nullptr)
{
}

LayerMenuStartHandle::~LayerMenuStartHandle()
{
	_layerMenuStart = nullptr;
}

bool LayerMenuStartHandle::init()
{
	auto isInit = false;

	do 
	{
		isInit = true;
	} while (0);

	return isInit;
}

void LayerMenuStartHandle::gameStart()
{
	/*auto manager = ManagerHandle::getInstance();
	manager->notify((int)ID_OBSERVER::HANDLE_LAYER_ENTITY, TO_HANDLE_LAYER_ENTITY::GAME_START);
	manager->notify((int)ID_OBSERVER::HANDLE_SCENE_GAME, TO_HANDLE_SCENE_GAME::LAYER_MENU_START_REMOVE);
	manager->notify((int)ID_OBSERVER::HANDLE_SCENE_GAME, TO_HANDLE_SCENE_GAME::LAYER_ACROSS_ADD);*/
}

void LayerMenuStartHandle::gameSaveLoad()
{
	/*auto manager = ManagerHandle::getInstance();
	manager->notify((int)ID_OBSERVER::HANDLE_LAYER_ENTITY, TO_HANDLE_LAYER_ENTITY::CREATE_WORLD);*///fortest
}

void LayerMenuStartHandle::gameSetting()
{

}
