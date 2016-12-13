#ifndef __CORE_ENTITY_RUNE_H__
#define __CORE_ENTITY_RUNE_H__

#include "Unit.h"
#include "IRune.h"
#include "HandleRune.h"

NS_BEGIN_GAME_ENTITY

class Rune : public Unit, IRune
{
public:
	CREATE_FUNC(Rune);

	Rune();
	~Rune();

	virtual bool init();

	virtual void addSkin(cocos2d::Sprite* skin);

	virtual HandleRune* getHandle() const { return dynamic_cast<HandleRune*>(Entity::getHandle()); }

protected:
	virtual HandleRune* createHandle();

private:
	
};

NS_END_END

#endif
