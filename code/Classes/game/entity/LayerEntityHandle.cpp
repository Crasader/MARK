#include "LayerEntity.h"
#include "defines/DefinesValue.h"
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
	stateCallback.insertCallback(StateLayerEntity::UNCREATE_WORLD, CC_CALLBACK_0(LayerEntityHandle::doAddEntity, this));
	stateCallback.insertCallback(StateLayerEntity::CREATING_WORLD, CC_CALLBACK_0(LayerEntityHandle::creatingEntity, this), CC_CALLBACK_1(LayerEntityHandle::creatingEntityCheck, this));
	stateCallback.insertCallback(StateLayerEntity::CREATED_WORLD, nullptr);
}

void LayerEntityHandle::update(float delta)
{
	auto& stateCallback = _model->getStateCallback();
	stateCallback.doCallbackByCurrentState(delta);
}

void LayerEntityHandle::attachObserver()
{
	idObserverSet((int)ID_OBSERVER::HANDLE_LAYER_ENTITY);
	ManagerHandle::getInstance()->attach(this);

	_model->setState(StateLayerEntity::UNCREATE_WORLD);
}

void LayerEntityHandle::doAddEntity()
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
		setEntityPostion(entity);
		setEntityBitIndex(entity);
		_view->addEntity(entity);
	}
}

void LayerEntityHandle::setEntityPostion(Entity* entity)
{
	auto model = entity->getHandle()->getModel();
	auto type = model->getType();
	auto id = model->getId();
	auto postion = _model->getEntityPostion(type, id);
	entity->setPosition(postion);
}

void LayerEntityHandle::setEntityBitIndex(Entity* entity)
{
	auto dataCreated = _model->getDataEntityCreated();
	auto bitIndex = dataCreated->getTotalBit();
	dataCreated->modifyTotalBit(bitIndex);
	auto model = entity->getHandle()->getModel();
	model->setBitIndex(bitIndex);
}

bool LayerEntityHandle::creatingEntityCheck(float delta)
{
	auto dataCreated = _model->getDataEntityCreated();
	return dataCreated->isAllBitTrue();//所有实体是否构造完成
}

void LayerEntityHandle::creatingEntity()
{
	_model->setState(StateLayerEntity::CREATED_WORLD);
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

void LayerEntityHandle::setDataEntityCreatedBit(va_list values)
{
	auto bitIndex = va_arg(values, int);
	_model->getDataEntityCreated()->setBit(bitIndex);
}
