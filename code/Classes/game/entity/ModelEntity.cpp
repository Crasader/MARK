#include "ModelEntity.h"
#include "Region.h"
#include "Creature.h"
#include "Rune.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

ModelEntity::ModelEntity() : _state(StateLayerEntity::ATTACH_OBSERVER), _dataEntityCreate(nullptr)
{
}

ModelEntity::~ModelEntity()
{
	_dicRegion.clear();
	_dicCreature.clear();
	_dicRune.clear();
	CC_SAFE_RELEASE_NULL(_dataEntityCreate);
}

bool ModelEntity::init()
{
	auto isInit = false;

	do
	{
		_dataEntityCreate = BitData::create();
		_dataEntityCreate->retain();

		isInit = true;
	} while (0);

	return isInit;
}

Entity* ModelEntity::getEntity(const TypeEntity& type, const int& id)
{
	Entity* entity = nullptr;
	auto dicEntity = getDicByTypeEntity(type);
	if (dicEntity.find(id) == dicEntity.end())
	{
		entity = createEntityByType(type);
		entity->setType(type);
		entity->setId(id);
		dicEntity.insert(id, entity);
	}
	else
	{
		entity = dicEntity.at(id);
	}
	return entity;
}

const Map<int, Entity*>& ModelEntity::getDicByTypeEntity(const TypeEntity& type)
{
	switch (type)
	{
	case TypeEntity::REGION:
		return _dicRegion;
	case TypeEntity::CREATURE:
		return _dicCreature;
	case TypeEntity::RUNE:
		return _dicRune;
	default:
		return {};
	}
}

Entity* ModelEntity::createEntityByType(const TypeEntity& type)
{
	switch (type)
	{
	case TypeEntity::REGION:
		return Region::create();
	case TypeEntity::CREATURE:
		return Creature::create();
	case TypeEntity::RUNE:
		return Rune::create();
	default:
		return{};
	}
}
