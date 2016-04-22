#ifndef __CORE_MAIN_SCENE_MAIN_H__
#define __CORE_MAIN_SCENE_MAIN_H__

#include "cocos2d.h"
#include "ISceneMain.h"
#include "HandleSceneMain.h"
#include "ui/menu/LayerMenuStart.h"
#include "ui/common/LayerResLoad.h"
#include "core/entity/LayerEntity.h"


class SceneMain : public cocos2d::Scene, ISceneMain
{
public:
	CREATE_FUNC(SceneMain);

	SceneMain();
	~SceneMain();
	
	virtual bool init();

	virtual void layerResLoadAdd();
	virtual void layerResLoadRemove();

	virtual void layerEntityAdd();
	virtual void layerEntityRemove();

	virtual void layerMenuStartAdd();
	virtual void layerMenuStartRemove();

private:
	HandleSceneMain* _handleSceneMain;
	userInerface::common::LayerResLoad* _layerResLoad;
	core::entity::LayerEntity* _layerEntity;
	LayerMenuStart* _layerMenuStart;

};

#endif
