#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "cocos2d.h"
#include "common/define/DefinesNamespace.h"
#include "HandleEntity.h"

NS_BEGIN_GAME_ENTITY

class Entity : public cocos2d::Node, IEntity
{
public:
	CREATE_FUNC(Entity);

	Entity();
	~Entity();

	virtual bool init();
	virtual void update(float delta);
	
	virtual void addSkin(cocos2d::Sprite* skin);

	virtual HandleEntity* getHandle() const { return _handle; }

protected:
	virtual HandleEntity* createHandle();

private:
	HandleEntity* _handle;

};

NS_END_END

#endif
