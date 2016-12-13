#ifndef __MODEL_LAYER_ENTITY_H__
#define __MODEL_LAYER_ENTITY_H__

#include "common/define/DefinesNamespace.h"
#include "cocos2d.h"
#include "common/bitData/BitData.h"
#include "Entity.h"

NS_BEGIN_GAME_ENTITY

enum class StateLayerEntity
{
	ATTACH_OBSERVER,
	UNCREATE_WORLD,
	CREATING_WORLD,
	CREATED_WORLD
};

class ModelLayerEntity : public cocos2d::Ref
{
public:
	CREATE_FUNC(ModelLayerEntity);

	ModelLayerEntity();
	~ModelLayerEntity();

	virtual bool init();

	Entity* getEntity(const TypeEntity& type, const int& id);

	CC_SYNTHESIZE(StateLayerEntity, _state, State);
	CC_SYNTHESIZE(BitData*, _dataEntityCreate, DataEntityCreated);

private:
	const cocos2d::Map<int, Entity*>& getDicByTypeEntity(const TypeEntity& type);
	Entity* createEntityByType(const TypeEntity& type);

	cocos2d::Map<int, Entity*> _dicNone;
	cocos2d::Map<int, Entity*> _dicRegion;
	cocos2d::Map<int, Entity*> _dicCreature;
	cocos2d::Map<int, Entity*> _dicRune;

};

NS_END_END

#endif