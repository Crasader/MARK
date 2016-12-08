#ifndef __LAYER_ENTITY_H__
#define __LAYER_ENTITY_H__

#include "cocos2d.h"
#include "ILayerEntity.h"
#include "HandleEntity.h"

NS_BEGIN_GAME_ENTITY

class LayerEntity : public cocos2d::Layer, ILayerEntity
{
public:
	CREATE_FUNC(LayerEntity);

	LayerEntity();
	~LayerEntity();

	virtual bool init();
	virtual void update(float delta);

	virtual void addEntity(Entity* entity);
	virtual void removeEntity(Entity* entity);

private:
	HandleEntity* _handleEntity;

};

NS_END_END

#endif