#include "LayerEntity.h"
#include "Region.h"
#include "Creature.h"
#include "Rune.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

LayerEntityModel::LayerEntityModel() : 
	_stateCallback(StateLayerEntity::ATTACH_OBSERVER),
	_dataEntityCreate(nullptr), 
	_dicNone(),
	_dicRegion(),
	_dicCreature(),
	_dicRune()
{
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

const cocos2d::Vec2& LayerEntityModel::getEntityPostion(const NS_GAME_ENTITY(TypeEntity)& type, const int& id)
{
	static std::map<TypeEntity, std::map<int, Vec2>> dicDicPostion =
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
	return dicDicPostion.at(type).at(id);
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
