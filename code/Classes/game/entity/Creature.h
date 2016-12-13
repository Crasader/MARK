#ifndef __CORE_ENTITY_CREATURE_H__
#define __CORE_ENTITY_CREATURE_H__

#include "Unit.h"
#include "ICreature.h"
#include "HandleCreature.h"

NS_BEGIN_GAME_ENTITY

class Creature : public Unit, ICreature
{
public:
	CREATE_FUNC(Creature);

	Creature();
	~Creature();

	virtual bool init();

	virtual void addSkin(cocos2d::Sprite* skin);

	virtual HandleCreature* getHandle() const { return dynamic_cast<HandleCreature*>(Unit::getHandle()); }
	
protected:
	virtual HandleCreature* createHandle();

private:

};

NS_END_END

#endif