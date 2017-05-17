#include "LayerEntity.h"
#include "Region.h"
#include "Creature.h"
#include "Rune.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

LayerEntity::LayerEntity() : _handle(nullptr)
{
}

LayerEntity::~LayerEntity()
{
	unscheduleUpdate();

	CC_SAFE_RELEASE_NULL(_handle);
}

bool LayerEntity::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Layer::init());

		_handle = LayerEntityHandle::create();
		_handle->retain();
		_handle->setView(this);

		scheduleUpdate();

		isInit = true;
	} while (0);

	return isInit;
}

void LayerEntity::update(float delta)
{
	_handle->update(delta);
}

void LayerEntity::addEntity(Entity* entity)
{
	addChild(entity);
}

void LayerEntity::addEntity(Entity* entity, const cocos2d::Vec2& postion)
{
	addChild(entity);
	entity->setPosition(postion);
}

void LayerEntity::removeEntity(Entity* entity)
{
	removeChild(entity);
}
