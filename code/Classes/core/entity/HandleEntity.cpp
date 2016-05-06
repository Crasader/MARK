#include "HandleEntity.h"
#include "model/define/DefinesValue.h"
#include "core/ManagerHandle.h"

USING_NS_CORE_ENTITY;

HandleEntity::HandleEntity() : _layerEntity(nullptr), _modelEntity(nullptr)
{
}

HandleEntity::~HandleEntity()
{
	ManagerHandle::getInstance()->detach(this);

	_layerEntity = nullptr;
	CC_SAFE_RELEASE_NULL(_modelEntity);
}

bool HandleEntity::init()
{
	auto isInit = false;

	do
	{
		idObserverSet((int)ID_OBSERVER::HANDLE_LAYER_ENTITY);
		ManagerHandle::getInstance()->attach(this);

		_modelEntity = ModelEntity::create();
		_modelEntity->retain();

		isInit = true;
	} while (0);

	return isInit;
}

void HandleEntity::updateBySubject(va_list values)
{
	auto type = va_arg(values, TO_HANDLE_LAYER_ENTITY);
	switch (type)
	{
	case TO_HANDLE_LAYER_ENTITY::CREATE_WORLD:
		createWorld();
		break;
	case TO_HANDLE_LAYER_ENTITY::START_ENGINE:
		_layerEntity->startEngine();
		break;
	default:
		break;
	}
}

void core::entity::HandleEntity::createWorld()
{
	_layerEntity->addRegioon(1000);//从主角位置添加地图
	_layerEntity->addRegioon(1001);
	_layerEntity->addRegioon(1002);
	_layerEntity->addRegioon(1003);
	_layerEntity->addRegioon(1004);
	_layerEntity->addRegioon(1005);
	_layerEntity->addRegioon(1006);
	_layerEntity->addRegioon(1007);
	_layerEntity->addRegioon(1008);//添加地图至填满

	_layerEntity->addCreature(1000);//添加主角
	_layerEntity->addCreature(1001);//添加其他生物
}
