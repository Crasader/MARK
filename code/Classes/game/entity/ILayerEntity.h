#ifndef __CORE_ENTITY_I_LAYER_ENTITY_H__
#define __CORE_ENTITY_I_LAYER_ENTITY_H__

#include "common/define/DefinesNamespace.h"
#include "common/bitData/BitData.h"

NS_BEGIN_GAME_ENTITY

class ILayerEntity
{
public:
	virtual void addRegioon(const int& id, BitData* dataCreate) {}
	virtual void addCreature(const int& id, BitData*dataCreate) {}
	virtual void addRune(const int& id, BitData* dataCreate) {}

};

NS_END_END

#endif