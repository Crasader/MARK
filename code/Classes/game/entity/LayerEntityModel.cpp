#include "LayerEntity.h"
#include "Region.h"
#include "Creature.h"
#include "Rune.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

LayerEntityModel::LayerEntityModel() : 
	_stateCallback(), 
	_dataEntityCreate(nullptr), 
	_dicNone(),
	_dicRegion(),
	_dicCreature(),
	_dicRune()
{
	setState(StateLayerEntity::ATTACH_OBSERVER);
}

LayerEntityModel::~LayerEntityModel()
{
	_dicRune.clear();
	_dicCreature.clear();
	_dicRegion.clear();
	_dicNone.clear();
	CC_SAFE_RELEASE_NULL(_dataEntityCreate);
	_stateCallback.clearDic();
}

bool LayerEntityModel::init()
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

Entity* LayerEntityModel::getEntity(const NS_GAME_ENTITY(TypeEntity)& type, const int& id)
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

const Map<int, Entity*>& LayerEntityModel::getDicByTypeEntity(const NS_GAME_ENTITY(TypeEntity)& type)
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

Entity* LayerEntityModel::createEntityByType(const NS_GAME_ENTITY(TypeEntity)& type)
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
