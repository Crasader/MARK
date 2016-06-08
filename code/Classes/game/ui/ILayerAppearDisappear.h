#pragma execution_character_set("utf-8")

#ifndef __GAME_UI_I_LAYER_APPEAR_DISAPPEAR_H__
#define __GAME_UI_I_LAYER_APPEAR_DISAPPEAR_H__

#include "cocos2d.h"

USING_NS_CC;

class ILayerAppearDisappear
{
public:
	virtual Layer *getThis() { return nullptr; }
	virtual void afterRunAppear() {}
	virtual void afterRunDisappear() {}
	virtual void dealRemoveFromParent() {}

private:

};

#endif
