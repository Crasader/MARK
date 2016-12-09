#ifndef __I_SCENE_WELCOME_H__
#define __I_SCENE_WELCOME_H__

#include "cocos2d.h"

class ISceneWelcome
{
public:
	virtual void addLayer(cocos2d::Layer* layer) {}
	virtual void removeLayer(cocos2d::Layer* layer) {}

};

#endif