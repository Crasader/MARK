#ifndef __MODEL_ENTITY_H__
#define __MODEL_ENTITY_H__

#include "cocos2d.h"
#include "common/define/DefinesNamespace.h"

NS_BEGIN_GAME_ENTITY

enum class StateEntity
{
	DEFAULT,
	UNCREATE_SKIN,
	CREATING_SKIN,
	CREATED_SKIN,
	UNINIT,
	STANDBY
};

enum class TypeEntity
{
	REGION,
	CREATURE,
	RUNE
};

class ModelEntity : public cocos2d::Ref
{
public:
	CREATE_FUNC(ModelEntity);

	ModelEntity();
	~ModelEntity();

	virtual bool init();

	cocos2d::Sprite* getSkin();

	CC_SYNTHESIZE_PASS_BY_REF(StateEntity, _state, State);
	CC_SYNTHESIZE_PASS_BY_REF(TypeEntity, _type, Type);
	CC_SYNTHESIZE(int, _id, Id);
	CC_SYNTHESIZE(int, _bitIndex, BitIndex);

protected:
	virtual cocos2d::Sprite* createSprite() { return nullptr; }//具体创建Sprite的方法，子类实现

private:
	cocos2d::Sprite* _skin;

};

NS_END_END

#endif