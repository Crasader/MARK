#ifndef __CORE_ENTITY_HANDLE_LAYER_ENTITY_H__
#define __CORE_ENTITY_HANDLE_LAYER_ENTITY_H__

#include "cocos2d.h"
#include "ILayerEntity.h"
#include "common/observer/Observer.h"

NS_BEGIN_CORE_ENTITY

class HandleLayerEntity : public cocos2d::Ref, Observer
{
public:
	CREATE_FUNC(HandleLayerEntity);

	HandleLayerEntity();
	~HandleLayerEntity();

	virtual bool init();
	virtual void updateBySubject(va_list values);
	virtual void createWorld();

	CC_SYNTHESIZE(ILayerEntity*, _layerEntity, LayerEntity);

private:

};

NS_END_END

#endif