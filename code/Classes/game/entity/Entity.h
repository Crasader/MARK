#ifndef __CORE_ENTITY_ENTITY_H__
#define __CORE_ENTITY_ENTITY_H__

#include "cocos2d.h"
#include "common/define/DefinesNamespace.h"
#include "common/bitData/BitData.h"

NS_BEGIN_GAME_ENTITY

enum class StateEntity
{
	UNINIT,
	STANDBY
};

class Entity : public cocos2d::Node
{
public:
	CREATE_FUNC(Entity);

	Entity();
	~Entity();

	virtual bool init();
	virtual void update(float delta);

	void setDataEntityCreate(const int& bitId, BitData* value);

	CC_SYNTHESIZE(int, _id, Id);
	CC_SYNTHESIZE_READONLY(cocos2d::Node*, _skin, Skin);
	CC_SYNTHESIZE(StateEntity, _state, StateEntity);

protected:
	virtual void createSkin();//add skin,set state standby

private:
	int _dataCreateBitId;
	BitData* _dataCreate;

};

NS_END_END

#endif
