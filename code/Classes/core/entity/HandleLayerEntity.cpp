#include "HandleLayerEntity.h"
#include "model/define/DefinesValue.h"
#include "../ManagerHandle.h"

USING_NS_CORE_ENTITY;

HandleLayerEntity::HandleLayerEntity() : _layerEntity(nullptr)
{
}

HandleLayerEntity::~HandleLayerEntity()
{
	ManagerHandle::getInstance()->detach(this);

	_layerEntity = nullptr;
}

bool HandleLayerEntity::init()
{
	auto isInit = false;

	do
	{
		idObserverSet((int)ID_OBSERVER::HANDLE_LAYER_ENTITY);
		ManagerHandle::getInstance()->attach(this);

		isInit = true;
	} while (0);

	return isInit;
}

void HandleLayerEntity::updateBySubject(va_list values)
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

void core::entity::HandleLayerEntity::createWorld()
{
	_layerEntity->addCreature(1000);//�������
	_layerEntity->addRegioon(1000);//������λ����ӵ�ͼ
	_layerEntity->addRegioon(1001);
	_layerEntity->addRegioon(1002);
	_layerEntity->addRegioon(1003);
	_layerEntity->addRegioon(1004);
	_layerEntity->addRegioon(1005);
	_layerEntity->addRegioon(1006);
	_layerEntity->addRegioon(1007);
	_layerEntity->addRegioon(1008);//��ӵ�ͼ������
	_layerEntity->addCreature(1001);//�����������
}
