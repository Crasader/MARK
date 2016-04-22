#include "HandleSceneMain.h"
#include "common/util/UtilRandom.h"
#include "model/define/DefinesValue.h"
#include "../ManagerHandle.h"

HandleSceneMain::HandleSceneMain() : _sceneMain(nullptr)
{
}

HandleSceneMain::~HandleSceneMain()
{
	ManagerHandle::getInstance()->detach(this);
	_sceneMain = nullptr;
}

bool HandleSceneMain::init()
{
	auto isInit = false;

	do
	{
		UtilRandom::initRandomSeed();

		idObserverSet((int)ID_OBSERVER::HANDLE_SCENE_MAIN);
		ManagerHandle::getInstance()->attach(this);

		isInit = true;
	} while (0);

	return isInit;
}

void HandleSceneMain::updateBySubject(va_list values)
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
	default:
		break;
	}
}
