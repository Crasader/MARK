#include "Entity.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

Entity::Entity() : _handle(nullptr)
{
}

Entity::~Entity()
{
	CC_SAFE_RELEASE_NULL(_handle);
}

bool Entity::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Node::init());
		
		_handle = createHandle();

		scheduleUpdate();

		isInit = true;
	} while (0);

	return isInit;
}

void Entity::update(float delta)
{
	_handle->update(delta);
}

void Entity::addSkin(cocos2d::Sprite* skin)
{
	this->addChild(skin);
}

HandleEntity* Entity::createHandle()
{
	auto handle = HandleEntity::create();
	handle->retain();
	handle->setEntity(this);
	return handle;
}
