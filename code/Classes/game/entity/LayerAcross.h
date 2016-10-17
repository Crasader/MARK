#ifndef __CORE_ENTITY_LAYER_ACROSS_H__
#define __CORE_ENTITY_LAYER_ACROSS_H__

#include "cocos2d.h"
#include "ILayerAcross.h"
#include "HandleAcross.h"

class LayerAcross : public cocos2d::Layer, ILayerAcross
{
public:
	CREATE_FUNC(LayerAcross);

	LayerAcross();
	~LayerAcross();

	virtual bool init();

private:
	HandleAcross* _handleAcross;

};

#endif
