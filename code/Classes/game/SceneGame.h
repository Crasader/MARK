#ifndef __GAME_SCENE_GAME_H__
#define __GAME_SCENE_GAME_H__

#include "cocos2d.h"
#include "ISceneGame.h"
#include "HandleGame.h"
#include "game/ui/LayerResLoad.h"
#include "game/entity/LayerEntity.h"
#include "game/ui/LayerMenuStart.h"
#include "game/ui/LayerMenuSystem.h"

class SceneGame : public cocos2d::Scene, ISceneGame
{
public:
	CREATE_FUNC(SceneGame);

	SceneGame();
	~SceneGame();
	
	virtual bool init();

	virtual void layerResLoadAdd();
	virtual void layerResLoadRemove();

	virtual void layerEntityAdd();
	virtual void layerEntityRemove();

	virtual void layerMenuStartAdd();
	virtual void layerMenuStartRemove();

	virtual void layerMenuSystemAdd();
	virtual void layerMenuSystemRemove();


private:
	HandleGame* _handleSceneMain;
	NS_UI_COMMON(LayerResLoad)* _layerResLoad;
	NS_GAME_ENTITY(LayerEntity)* _layerEntity;
	LayerMenuStart* _layerMenuStart;
	LayerMenuSystem* _layerMenuSystem;

};

#endif
