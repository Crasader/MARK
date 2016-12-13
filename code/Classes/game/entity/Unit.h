#ifndef __CORE_ENTITY_UNIT_H__
#define __CORE_ENTITY_UNIT_H__

#include "Entity.h"
#include "IUnit.h"
#include "HandleUnit.h"

NS_BEGIN_GAME_ENTITY

class Unit : public Entity, IUnit
{
public:
	CREATE_FUNC(Unit);

	Unit();
	~Unit();

	virtual bool init();

	virtual void addSkin(cocos2d::Sprite* skin);

	virtual HandleUnit* getHandle() const { return dynamic_cast<HandleUnit*>(Entity::getHandle()); }

protected:
	virtual HandleUnit* createHandle();

private:

};

NS_END_END

#endif