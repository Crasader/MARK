#include "ModelLayerEntity.h"
#include "Region.h"
#include "Creature.h"
#include "Rune.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

ModelLayerEntity::ModelLayerEntity() : _state(StateLayerEntity::ATTACH_OBSERVER), _dataEntityCreate(nullptr)
{
}

ModelLayerEntity::~ModelLayerEntity()
{
	_dicRegion.clear();
	_dicCreature.clear();
	_dicRune.clear();
	CC_SAFE_RELEASE_NULL(_dataEntityCreate);
}

bool ModelLayerEntity::init()
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

Entity* ModelLayerEntity::getEntity(const TypeEntity& type, const int& id)
{
	Entity* entity = nullptr;
	auto dicEntity = getDicByTypeEntity(type);
	if (dicEntity.find(id) == dicEntity.end())
	{
		entity = createEntityByType(type);
		auto model = entity->getHandle()->getModel();
		model->setType(type);
		model->setId(id);
		dicEntity.insert(id, entity);
	}
	else
	{
		entity = dicEntity.at(id);
	}
	return entity;
}

const Map<int, Entity*>& ModelLayerEntity::getDicByTypeEntity(const TypeEntity& type)
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
		return _dicNone;
	}
}

Entity* ModelLayerEntity::createEntityByType(const TypeEntity& type)
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
		return nullptr;
	}
}
