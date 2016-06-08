#include "LayerEntity.h"
#include "Region.h"
#include "Creature.h"
#include "Rune.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

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

void LayerEntity::addRegioon(const int& id)
{
	auto region = Region::create();
	region->setId(id);
	addChild(region);
	_vecEntity.pushBack(region);

	std::vector<Vec2> vecPostion = {
		Vec2(320.0f, 480.0f),
		Vec2(320.0f, 270.0f), Vec2(320.0f, 690.0f),//上下
		Vec2(110.0f, 480.0f), Vec2(530.0f, 480.0f),//左右
		Vec2(110.0f, 270.0f), Vec2(530.0f, 690.0f),//左上右下
		Vec2(110.0f, 690.0f), Vec2(530.0f, 270.0f) };//左下右上

	region->setPosition(vecPostion[(id - 1000)]);
}

void LayerEntity::addCreature(const int& id)
{
	auto creature = Creature::create();
	creature->setId(id);
	addChild(creature);
	_vecEntity.pushBack(creature);


	if (id == 1000)
	{
		creature->setPosition(Vec2(320.0f, 270.0f));
	}
	else
	{
		creature->setPosition(Vec2(320.0f, 690.0f));
	}

}

void LayerEntity::addRune()
{
	auto rune = Rune::create();
	addChild(rune);
	_vecEntity.pushBack(rune);
}

void LayerEntity::startEngine()
{
	
}
