#ifndef __UI_MENU_I_MENU_H__
#define __UI_MENU_I_MENU_H__

#include "cocos2d.h"

class ILayerMenuStart
{
public:
	virtual cocos2d::Layer * getSkin() { return nullptr; }
};

#endif