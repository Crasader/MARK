#ifndef __CORE_ENTITY_HANDLE_ENTITY_H__
#define __CORE_ENTITY_HANDLE_ENTITY_H__

#include "cocos2d.h"
#include "common/observer/Observer.h"
#include "ILayerEntity.h"
#include "ModelEntity.h"

NS_BEGIN_GAME_ENTITY

class HandleEntity : public cocos2d::Ref, Observer
{
public:
	CREATE_FUNC(HandleEntity);

	HandleEntity();
	~HandleEntity();

	virtual bool init();
	virtual void updateBySubject(va_list values);
	virtual void createWorld();

	void setLayerEntity(ILayerEntity* val) { _layerEntity = val; }

private:
	ILayerEntity* _layerEntity;
	ModelEntity* _modelEntity;

};

NS_END_END

#endif