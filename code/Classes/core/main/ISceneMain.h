#ifndef __CORE_MAIN_I_SCENE_MAIN_H__
#define __CORE_MAIN_I_SCENE_MAIN_H__

#include "cocos2d.h"

class ISceneMain
{
public:
	virtual void layerResLoadAdd() {}
	virtual void layerResLoadRemove() {}

	virtual void layerEntityAdd() {}
	virtual void layerEntityRemove() {}

	virtual void layerMenuStartAdd() {}
	virtual void layerMenuStartRemove() {}
};

#endif