#ifndef _ENTITY_ENTITY_H_
#define _ENTITY_ENTITY_H_

#include "cocos2d.h"

USING_NS_CC;

class Entity : public Node
{
public:
	CREATE_FUNC(Entity);

	Entity();
	~Entity();

	virtual bool init();

private:

};

#endif
