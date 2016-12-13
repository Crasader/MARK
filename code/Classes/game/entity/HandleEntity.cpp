#include "HandleEntity.h"
#include "game/ManagerHandle.h"
#include "common/define/DefinesValue.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

HandleEntity::HandleEntity() : _entity(nullptr), _model(nullptr)
{
}

HandleEntity::~HandleEntity()
{
	setEntity(nullptr);
	CC_SAFE_RELEASE_NULL(_model);
}

bool HandleEntity::init()
{
	auto isInit = false;

	do
	{
		_model = createModel();

		isInit = true;
	} while (0);

	return isInit;
}

ModelEntity* HandleEntity::createModel()
{
	auto model = ModelEntity::create();
	model->retain();
	return model;
}

void HandleEntity::update(float delta)
{
	auto state = getModel()->getState();
	if (StateEntity::DEFAULT == state)
	{
		return;
	}

	if (StateEntity::UNCREATE_SKIN == state)
	{
		createSkin();
		return;
	}

	if (StateEntity::CREATING_SKIN == state)
	{
		creatingSkin();
		return;
	}

	if (StateEntity::CREATED_SKIN == state)
	{
		createdSkin();
		return;
	}
}

void HandleEntity::createSkin()
{
	auto skin = getModel()->getSkin();
	/*auto entity = getEntity();
	entity->addSkin(skin);*/
	_entity->addSkin(skin);

	_entity->doSomething();

	getModel()->setState(StateEntity::CREATING_SKIN);
}

void HandleEntity::creatingSkin()
{
	getModel()->setState(StateEntity::CREATED_SKIN);
}

void HandleEntity::createdSkin()
{
	auto bitIndex = getModel()->getBitIndex();
	auto managerHandle = ManagerHandle::getInstance();
	managerHandle->notify((int)ID_OBSERVER::HANDLE_LAYER_ENTITY, TO_HANDLE_LAYER_ENTITY::ENTITY_CREATED, bitIndex);

	getModel()->setState(StateEntity::DEFAULT);
}
