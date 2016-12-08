#ifndef __SCENE_GAME_H__
#define __SCENE_GAME_H__

#include "cocos2d.h"
#include "ISceneGame.h"
#include "HandleGame.h"

class SceneGame : public cocos2d::Scene, ISceneGame
{
public:
	CREATE_FUNC(SceneGame);

	SceneGame();
	~SceneGame();
	
	virtual bool init();

	virtual void update(float delta);

	virtual void addLayer(cocos2d::Layer* layer);
	virtual void removeLayer(cocos2d::Layer* layer);

private:
	HandleGame* _handleGame;

};

#endif
