#include "Entity.h"
#include "game/ManagerHandle.h"
#include "common/define/DefinesValue.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

EntityHandle::EntityHandle() : _view(nullptr), _model(nullptr)
{
}

EntityHandle::~EntityHandle()
{
	setView(nullptr);
	CC_SAFE_RELEASE_NULL(_model);
}

bool EntityHandle::init()
{
	auto isInit = false;

	do
	{
		_model = createModel();
		
		attachStateCallback();

		isInit = true;
	} while (0);

	return isInit;
}

void EntityHandle::attachStateCallback()
{
	auto& stateCallback = _model->getStateCallback();
	stateCallback.insertCallback(StateEntity::DEFAULT, nullptr);
	stateCallback.insertCallback(StateEntity::UNCREATE_SKIN, CC_CALLBACK_0(EntityHandle::createSkin, this));
	stateCallback.insertCallback(StateEntity::CREATING_SKIN, CC_CALLBACK_0(EntityHandle::creatingSkin, this));
	stateCallback.insertCallback(StateEntity::CREATED_SKIN, CC_CALLBACK_0(EntityHandle::createdSkin, this));
}

void EntityHandle::update(float delta)
{
	auto& stateCallback = _model->getStateCallback();
	stateCallback.doCallbackByCurrentState(delta);
}

void EntityHandle::createSkin()
{
	auto skin = getModel()->getSkin();
	/*auto entity = getEntity();
	entity->addSkin(skin);*/
	_view->addSkin(skin);

	_view->doSomething();

	getModel()->setState(StateEntity::CREATING_SKIN);
}

void EntityHandle::creatingSkin()
{
	getModel()->setState(StateEntity::CREATED_SKIN);
}

void EntityHandle::createdSkin()
{
	auto bitIndex = getModel()->getBitIndex();
	auto managerHandle = ManagerHandle::getInstance();
	managerHandle->notify((int)ID_OBSERVER::HANDLE_LAYER_ENTITY, TO_HANDLE_LAYER_ENTITY::ENTITY_CREATED, bitIndex);

	getModel()->setState(StateEntity::DEFAULT);
}

EntityModel* EntityHandle::createModel()
{
	auto model = EntityModel::create();
	model->retain();
	return model;
}
