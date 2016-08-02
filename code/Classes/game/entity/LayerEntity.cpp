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

		scheduleUpdate();

		isInit = true;
	} while (0);

	return isInit;
}

void LayerEntity::update(float delta)
{
	_handleEntity->update(delta);
}

void LayerEntity::addRegioon(const int& id, BitData* dataCreate)
{
	auto region = Region::create();
	region->setId(id);
	addChild(region);
	_vecEntity.pushBack(region);

	std::map<int, Vec2> dicPostion = 
	{
		{1000, Vec2(320.0f, 480.0f) },
		{ 1001, Vec2(320.0f, 270.0f) },{ 1002, Vec2(320.0f, 690.0f) },//上下
		{ 1003, Vec2(110.0f, 480.0f) },{ 1004, Vec2(530.0f, 480.0f) },//左右
		{ 1005, Vec2(110.0f, 270.0f) },{ 1006, Vec2(530.0f, 690.0f) },//左上右下
		{ 1007, Vec2(110.0f, 690.0f) },{ 1008, Vec2(530.0f, 270.0f) } //左下右上
	};

	region->setPosition(dicPostion[id]);

	auto bitId = dataCreate->getTotalBit();
	dataCreate->modifyTotalBit(bitId + 1);
	region->setDataEntityCreate(bitId, dataCreate);
}

void LayerEntity::addCreature(const int& id, BitData* dataCreate)
{
	auto creature = Creature::create();
	creature->setId(id);
	addChild(creature);
	_vecEntity.pushBack(creature);

	std::map<int, Vec2> dicPostion =
	{
		{ 1000, Vec2(320.0f, 270.0f) },
		{ 1001, Vec2(320.0f, 690.0f) }
	};

	creature->setPosition(dicPostion[id]);

	auto bitId = dataCreate->getTotalBit();
	dataCreate->modifyTotalBit(bitId + 1);
	creature->setDataEntityCreate(bitId, dataCreate);
}

void LayerEntity::addRune(const int& id, BitData* dataCreate)
{
	auto rune = Rune::create();
	addChild(rune);
	_vecEntity.pushBack(rune);

	auto bitId = dataCreate->getTotalBit();
	dataCreate->modifyTotalBit(bitId + 1);
	rune->setDataEntityCreate(bitId, dataCreate);
}
