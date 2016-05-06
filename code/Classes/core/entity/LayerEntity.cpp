#include "LayerEntity.h"
#include "Region.h"
#include "Creature.h"
#include "Rune.h"

USING_NS_CC;
USING_NS_CORE_ENTITY;

LayerEntity::LayerEntity() : _handleEntity(nullptr)
{
}

LayerEntity::~LayerEntity()
{
	_vecEntity.clear();
	CC_SAFE_RELEASE_NULL(_handleEntity);
}

bool LayerEntity::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Layer::init());

		_handleEntity = HandleEntity::create();
		_handleEntity->retain();
		_handleEntity->setLayerEntity(this);

		_handleEntity->createWorld();

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

	std::vector<Vec2> vecPostion = {
		Vec2(320.0f, 480.0f),
		Vec2(320.0f, 380.0f), Vec2(320.0f, 580.0f),
		Vec2(220.0f, 480.0f), Vec2(420.0f, 480.0f),
		Vec2(220.0f, 380.0f), Vec2(420.0f, 580.0f),
		Vec2(220.0f, 580.0f), Vec2(420.0f, 380.0f) };

	region->setPosition(vecPostion[(id - 1000)]);
}

void core::entity::LayerEntity::addCreature(const int& id)
{
	auto creature = Creature::create();
	creature->setId(id);
	addChild(creature);
	_vecEntity.pushBack(creature);


	if (id == 1000)
	{
		creature->setPosition(Vec2(320.0f, 280.0f));
	}
	else
	{
		creature->setPosition(Vec2(320.0f, 680.0f));
	}

}

void core::entity::LayerEntity::addRune()
{
	auto rune = Rune::create();
	addChild(rune);
	_vecEntity.pushBack(rune);
}

void LayerEntity::startEngine()
{
	
}
