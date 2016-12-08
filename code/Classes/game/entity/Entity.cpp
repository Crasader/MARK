#include "Entity.h"
#include "game/ManagerHandle.h"
#include "common/define/DefinesValue.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

Entity::Entity() : 
	_id(0), 
	_bitIndex(0), 
	_skin(nullptr), 
	_state(StateEntity::UNINIT)
{
}

Entity::~Entity()
{
	_skin = nullptr;
}

bool Entity::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Node::init());
		
		scheduleUpdate();

		isInit = true;
	} while (0);

	return isInit;
}

void Entity::update(float delta)
{
	if (_state == StateEntity::UNINIT)
	{
		createSkin();
	}
	else if (_state == StateEntity::STANDBY)
	{

	}
}

void Entity::createSkin()
{
	this->addChild(_skin);
	_state = StateEntity::STANDBY;

	auto managerHandle = ManagerHandle::getInstance();
	managerHandle->notify((int)ID_OBSERVER::HANDLE_LAYER_ENTITY, TO_HANDLE_LAYER_ENTITY::ENTITY_CREATED, _bitIndex);
}
