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
	case TO_HANDLE_LAYER_ENTITY::ENTITY_CREATED:
		setDataEntityCreatedBit(values);
		break;
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

	if (StateLayerEntity::ATTACH_OBSERVER == state)
	{
		attachObserver();
		return;
	}

	if (StateLayerEntity::UNCREATE_WORLD == state)
	{
		addEntity();
		return;
	}

	if (StateLayerEntity::CREATING_WORLD == state)
	{
		creatingEntity();
		return;
	}

	if (StateLayerEntity::CREATED_WORLD == state)
	{

		return;
	}
}

void HandleEntity::attachObserver()
{
	idObserverSet((int)ID_OBSERVER::HANDLE_LAYER_ENTITY);
	ManagerHandle::getInstance()->attach(this);

	_modelEntity->setState(StateLayerEntity::UNCREATE_WORLD);
}

void HandleEntity::addEntity()
{
	addEntityByTypeNum(TypeEntity::REGION, 9);//������λ����ӵ�ͼ,��ӵ�ͼ������

	addEntityByTypeNum(TypeEntity::CREATURE, 2);//������Ǽ���������

	_modelEntity->setState(StateLayerEntity::CREATING_WORLD);
}

void HandleEntity::addEntityByTypeNum(const NS_GAME_ENTITY(TypeEntity)& type, const int& num)
{
	auto id = 1000;
	for (auto i = 0; i < num; i++)
	{
		auto entity = _modelEntity->getEntity(type, id + i);
		_layerEntity->addEntity(entity);
		setEntityBitIndex(entity);
	}
}

void HandleEntity::setEntityBitIndex(Entity* entity)
{
	auto dataCreated = _modelEntity->getDataEntityCreated();
	auto bitIndex = dataCreated->getTotalBit();
	dataCreated->modifyTotalBit(bitIndex + 1);
	entity->setBitIndex(bitIndex);
}

void HandleEntity::setDataEntityCreatedBit(va_list values)
{
	auto bitIndex = va_arg(values, int);
	_modelEntity->getDataEntityCreated()->setBit(bitIndex);
}

void HandleEntity::creatingEntity()
{
	auto dataCreated = _modelEntity->getDataEntityCreated();
	if (dataCreated->isAllBitTrue())//����ʵ�幹�����
	{
		_modelEntity->setState(StateLayerEntity::CREATED_WORLD);
		return;
	}
}
