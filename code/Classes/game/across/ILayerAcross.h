#ifndef __I_LAYER_ACROSS_H__
#define __I_LAYER_ACROSS_H__

#include "cocos2d.h"

class ILayerAcross
{
public:
	virtual void setContentSizeByAcrossObject(const cocos2d::Size& size) {}
	virtual void addEvent(cocos2d::EventListenerTouchOneByOne* listener) {}
	virtual void removeEvent(cocos2d::EventListenerTouchOneByOne* listener) {}
	virtual void addNodeTo(cocos2d::Node* node, const cocos2d::Vec2& postion) {}

};

#endif