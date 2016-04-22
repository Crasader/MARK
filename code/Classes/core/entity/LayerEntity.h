#ifndef __CORE_ENTITY_LAYER_ENTITY_H__
#define __CORE_ENTITY_LAYER_ENTITY_H__

#include "cocos2d.h"
#include "ILayerEntity.h"
#include "HandleLayerEntity.h"
#include "Entity.h"

NS_BEGIN_CORE_ENTITY

class LayerEntity : public cocos2d::Layer, ILayerEntity
{
public:
	CREATE_FUNC(LayerEntity);

	LayerEntity();
	~LayerEntity();

	virtual bool init();
	virtual void addRegioon(const int& id);
	virtual void addCreature(const int& id);
	virtual void addRune();
	virtual void startEngine();

	virtual void update(float delta);

private:
	cocos2d::Vector<core::entity::Entity*> _vecEntity;
	HandleLayerEntity* _handleLayerEntity;

};

NS_END_END

#endif