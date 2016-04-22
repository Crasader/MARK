#ifndef __CORE_ENTITY_I_LAYER_ENTITY_H__
#define __CORE_ENTITY_I_LAYER_ENTITY_H__

#include "model/define/DefinesNamespace.h"

NS_BEGIN_CORE_ENTITY

class ILayerEntity
{
public:
	virtual void addRegioon(const int& id) {}
	virtual void addCreature(const int& id) {}
	virtual void addRune() {}
	virtual void startEngine() {}

};

NS_END_END

#endif