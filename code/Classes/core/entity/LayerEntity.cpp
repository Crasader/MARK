#include "LayerEntity.h"
#include "Region.h"
#include "Creature.h"
#include "Rune.h"

USING_NS_CC;
USING_NS_CORE_ENTITY;

LayerEntity::LayerEntity() : _handleLayerEntity(nullptr)
{
}

LayerEntity::~LayerEntity()
{
	_vecEntity.clear();
	CC_SAFE_RELEASE_NULL(_handleLayerEntity);
}

bool LayerEntity::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Layer::init());

		_handleLayerEntity = HandleLayerEntity::create();
		_handleLayerEntity->retain();
		_handleLayerEntity->setLayerEntity(this);

		isInit = true;
	} while (0);

	return isInit;
}

void core::entity::LayerEntity::addRegioon(const int& id)
{
	auto region = Region::create();
	region->setId(id);
	addChild(region);
	_vecEntity.pushBack(region);
}

void core::entity::LayerEntity::addCreature(const int& id)
{
	auto creature = Creature::create();
	creature->setId(id);
	addChild(creature);
	_vecEntity.pushBack(creature);
}

void core::entity::LayerEntity::addRune()
{
	auto rune = Rune::create();
	addChild(rune);
	_vecEntity.pushBack(rune);
}

void LayerEntity::startEngine()
{
	scheduleUpdate();
}

void LayerEntity::update(float delta)
{
	for (auto iter = _vecEntity.rbegin(); iter != _vecEntity.rend(); iter++)
	{
		
	}
}
