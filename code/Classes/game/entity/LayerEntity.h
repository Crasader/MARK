#ifndef __CORE_ENTITY_LAYER_ENTITY_H__
#define __CORE_ENTITY_LAYER_ENTITY_H__

#include "cocos2d.h"
#include "ILayerEntity.h"
#include "HandleEntity.h"
#include "Entity.h"

NS_BEGIN_GAME_ENTITY

class LayerEntity : public cocos2d::Layer, ILayerEntity
{
public:
	CREATE_FUNC(LayerEntity);

	LayerEntity();
	~LayerEntity();

	virtual bool init();
	virtual void update(float delta);
	virtual void addRegioon(const int& id, BitData* dataCreate);
	virtual void addCreature(const int& id, BitData*dataCreate);
	virtual void addRune(const int& id, BitData* dataCreate);

private:
	cocos2d::Vector<Entity*> _vecEntity;
	HandleEntity* _handleEntity;

};

NS_END_END

#endif