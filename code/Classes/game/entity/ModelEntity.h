#ifndef __CORE_ENTITY_MODEL_ENTITY_H__
#define __CORE_ENTITY_MODEL_ENTITY_H__

#include "common/define/DefinesNamespace.h"
#include "cocos2d.h"
#include "common/bitData/BitData.h"

NS_BEGIN_GAME_ENTITY

enum class StateLayerEntity
{
	WORLD_UNCREATE,
	WORLD_CREATING,
	WORLD_CREATED
};

class ModelEntity : public cocos2d::Ref
{
public:
	CREATE_FUNC(ModelEntity);

	ModelEntity();
	~ModelEntity();

	virtual bool init();

	CC_SYNTHESIZE(StateLayerEntity, _state, State);
	CC_SYNTHESIZE(BitData*, _dataEntityCreate, DataEntityCreate);
	CC_SYNTHESIZE_READONLY_PASS_BY_REF(int, _currentEntityCreate, CurrentEntityCreate);

private:
	
};

NS_END_END

#endif