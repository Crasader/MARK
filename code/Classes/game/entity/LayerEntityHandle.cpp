#include "LayerEntity.h"
#include "common/define/DefinesValue.h"
#include "game/ManagerHandle.h"

USING_NS_GAME_ENTITY;

LayerEntityHandle::LayerEntityHandle() : _view(nullptr), _model(nullptr)
{
}

LayerEntityHandle::~LayerEntityHandle()
{
	ManagerHandle::getInstance()->detach(this);

	_view = nullptr;
	CC_SAFE_RELEASE_NULL(_model);
}

bool LayerEntityHandle::init()
{
	auto isInit = false;

	do
	{
		_model = LayerEntityModel::create();
		_model->retain();

		attachStateCallback();

		isInit = true;
	} while (0);

	return isInit;
}

void LayerEntityHandle::attachStateCallback()
{
	auto& stateCallback = _model->getStateCallback();
	stateCallback.insertCallback(StateLayerEntity::DEFAULT, nullptr);
	stateCallback.insertCallback(StateLayerEntity::ATTACH_OBSERVER, CC_CALLBACK_0(LayerEntityHandle::attachObserver, this));
	stateCallback.insertCallback(StateLayerEntity::UNCREATE_WORLD, CC_CALLBACK_0(LayerEntityHandle::addEntity, this));
	stateCallback.insertCallback(StateLayerEntity::CREATING_WORLD, CC_CALLBACK_0(LayerEntityHandle::creatingEntity, this));
	stateCallback.insertCallback(StateLayerEntity::CREATED_WORLD, nullptr);
}

void LayerEntityHandle::update(float delta)
{
	auto& stateCallback = _model->getStateCallback();
	stateCallback.doCallbackByCurrentState(delta);
}

void LayerEntityHandle::updateBySubject(va_list values)
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

void LayerEntityHandle::attachObserver()
{
	idObserverSet((int)ID_OBSERVER::HANDLE_LAYER_ENTITY);
	ManagerHandle::getInstance()->attach(this);

	_model->setState(StateLayerEntity::UNCREATE_WORLD);
}

void LayerEntityHandle::addEntity()
{
	addEntityByTypeNum(TypeEntity::REGION, 9);//从中心位置添加地图,添加地图至填满

	addEntityByTypeNum(TypeEntity::CREATURE, 2);//添加主角及其他生物

	_model->setState(StateLayerEntity::CREATING_WORLD);
}

void LayerEntityHandle::addEntityByTypeNum(const NS_GAME_ENTITY(TypeEntity)& type, const int& num)
{
	auto id = 1000;
	for (auto i = 0; i < num; i++)
	{
		auto entity = _model->getEntity(type, id + i);
		_view->addEntity(entity);
		setEntityBitIndex(entity);
	}
}

void LayerEntityHandle::setEntityBitIndex(Entity* entity)
{
	auto dataCreated = _model->getDataEntityCreated();
	auto bitIndex = dataCreated->getTotalBit();
	dataCreated->modifyTotalBit(bitIndex);
	auto model = entity->getHandle()->getModel();
	model->setBitIndex(bitIndex);
}

void LayerEntityHandle::setDataEntityCreatedBit(va_list values)
{
	auto bitIndex = va_arg(values, int);
	_model->getDataEntityCreated()->setBit(bitIndex);
}

void LayerEntityHandle::creatingEntity()
{
	auto dataCreated = _model->getDataEntityCreated();
	if (dataCreated->isAllBitTrue())//所有实体构造完成
	{
		_model->setState(StateLayerEntity::CREATED_WORLD);
		return;
	}
}
