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
	
	std::map<TypeEntity, std::map<int, Vec2>> dicDicPostion =
	{
		{
			TypeEntity::REGION,
			{
				{ 1000, Vec2(320.0f, 480.0f) },
				{ 1001, Vec2(320.0f, 270.0f) },{ 1002, Vec2(320.0f, 690.0f) },//上下
				{ 1003, Vec2(110.0f, 480.0f) },{ 1004, Vec2(530.0f, 480.0f) },//左右
				{ 1005, Vec2(110.0f, 270.0f) },{ 1006, Vec2(530.0f, 690.0f) },//左上右下
				{ 1007, Vec2(110.0f, 690.0f) },{ 1008, Vec2(530.0f, 270.0f) } //左下右上
			} 
		},
		{
			TypeEntity::CREATURE,
			{
				{ 1000, Vec2(320.0f, 270.0f) },
				{ 1001, Vec2(320.0f, 690.0f) }
			}
		}
	};

	auto model = entity->getHandle()->getModel();
	auto type = model->getType();
	auto id = model->getId();
	entity->setPosition(dicDicPostion[type][id]);
}

void LayerEntity::removeEntity(Entity* entity)
{
	removeChild(entity);
}
