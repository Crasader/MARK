#ifndef __I_LAYER_ENTITY_H__
#define __I_LAYER_ENTITY_H__

#include "common/define/DefinesNamespace.h"
#include "Entity.h"

NS_BEGIN_GAME_ENTITY

class ILayerEntity
{
public:
	virtual void addEntity(Entity* entity) {}
	virtual void removeEntity(Entity* entity) {}

};

NS_END_END

#endif