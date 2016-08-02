#include "HandleEntity.h"
#include "common/define/DefinesValue.h"
#include "game/ManagerHandle.h"

USING_NS_GAME_ENTITY;

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
	case TO_HANDLE_LAYER_ENTITY::GAME_START:
		break;
	case TO_HANDLE_LAYER_ENTITY::GAME_STOP:
		break;
	default:
		break;
	}
}

void HandleEntity::update(float delta)
{
	auto state = _modelEntity->getState();
	if (StateLayerEntity::WORLD_UNCREATE == state)
	{
		entityAdd();
		return;
	}

	if (StateLayerEntity::WORLD_CREATING == state)
	{
		entityCreating();
		return;
	}

	if (StateLayerEntity::WORLD_CREATED == state)
	{

		return;
	}
}

void HandleEntity::entityAdd()
{
	auto data = _modelEntity->getDataEntityCreate();

	_layerEntity->addRegioon(1000, data);//������λ����ӵ�ͼ
	_layerEntity->addRegioon(1001, data);
	_layerEntity->addRegioon(1002, data);
	_layerEntity->addRegioon(1003, data);
	_layerEntity->addRegioon(1004, data);
	_layerEntity->addRegioon(1005, data);
	_layerEntity->addRegioon(1006, data);
	_layerEntity->addRegioon(1007, data);
	_layerEntity->addRegioon(1008, data);//��ӵ�ͼ������

	_layerEntity->addCreature(1000, data);//�������
	_layerEntity->addCreature(1001, data);//�����������

	_modelEntity->setState(StateLayerEntity::WORLD_CREATING);
}

void HandleEntity::entityCreating()
{
	auto data = _modelEntity->getDataEntityCreate();
	if (data->isAllBitTrue())//����ʵ�幹�����
	{
		_modelEntity->setState(StateLayerEntity::WORLD_CREATED);
		return;
	}
}
