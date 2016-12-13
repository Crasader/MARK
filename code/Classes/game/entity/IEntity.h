#ifndef __I_ENTITY_H__
#define __I_ENTITY_H__

#include "cocos2d.h"
#include "common/define/DefinesNamespace.h"

NS_BEGIN_GAME_ENTITY

class IEntity
{
public:
	virtual void addSkin(cocos2d::Sprite* skin) {}
	virtual void doSomething() {}

};

NS_END_END

#endif