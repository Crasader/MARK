#ifndef __GAME_I_SCENE_GAME_H__
#define __GAME_I_SCENE_GAME_H__

#include "cocos2d.h"

class ISceneGame
{
public:
	virtual void layerResLoadAdd() {}
	virtual void layerResLoadRemove() {}

	virtual void layerEntityAdd() {}
	virtual void layerEntityRemove() {}

	virtual void layerMenuStartAdd() {}
	virtual void layerMenuStartRemove() {}

	virtual void layerMenuSystemAdd() {}
	virtual void layerMenuSystemRemove() {}
};

#endif