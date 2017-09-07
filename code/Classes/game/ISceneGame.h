#ifndef __I_SCENE_GAME_H__
#define __I_SCENE_GAME_H__

#include "cocos2d.h"

class ISceneGame
{
public:
	virtual void addLayer(cocos2d::Layer* layer) {}
	virtual void removeLayer(cocos2d::Layer* layer) {}

};
#endif