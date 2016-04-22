#include "Entity.h"

USING_NS_CC;
USING_NS_CORE_ENTITY;

Entity::Entity() : _id(0), _state(StateEntity::UNINIT), _skin(nullptr)
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
}
