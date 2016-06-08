#ifndef __CORE_ENTITY_MODEL_ENTITY_H__
#define __CORE_ENTITY_MODEL_ENTITY_H__

#include "common/define/DefinesNamespace.h"
#include "cocos2d.h"

NS_BEGIN_GAME_ENTITY

class ModelEntity : public cocos2d::Ref
{
public:
	CREATE_FUNC(ModelEntity);

	ModelEntity();
	~ModelEntity();

	virtual bool init();

private:
	bool _isEngineStart;

};

NS_END_END

#endif