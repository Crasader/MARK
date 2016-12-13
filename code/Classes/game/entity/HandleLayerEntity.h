#ifndef __HANDLE_LAYER_ENTITY_H__
#define __HANDLE_LAYER_ENTITY_H__

#include "cocos2d.h"
#include "common/observer/Observer.h"
#include "ILayerEntity.h"
#include "ModelLayerEntity.h"

NS_BEGIN_GAME_ENTITY

class HandleLayerEntity : public cocos2d::Ref, Observer
{
public:
	CREATE_FUNC(HandleLayerEntity);

	HandleLayerEntity();
	~HandleLayerEntity();

	virtual bool init();
	void update(float delta);
	
	virtual void updateBySubject(va_list values);
	
	void setLayerEntity(ILayerEntity* val) { _layerEntity = val; }

private:
	void attachObserver();
	void addEntity();
	void addEntityByTypeNum(const NS_GAME_ENTITY(TypeEntity)& type, const int& num);
	void setEntityBitIndex(Entity* entity);
	void setDataEntityCreatedBit(va_list values);
	void creatingEntity();

	ILayerEntity* _layerEntity;
	ModelLayerEntity* _modelEntity;

};

NS_END_END

#endif