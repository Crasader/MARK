#ifndef __SCENE_WELCOME_H__
#define __SCENE_WELCOME_H__

#include "cocos2d.h"
#include "ISceneWelcome.h"
#include "HandleWelcome.h"

class SceneWelcome : public cocos2d::Scene,ISceneWelcome
{
public:
	CREATE_FUNC(SceneWelcome);

	SceneWelcome();
	~SceneWelcome();

	virtual bool init();

	virtual void update(float delta);

	virtual void addLayer(cocos2d::Layer* layer);
	virtual void removeLayer(cocos2d::Layer* layer);

private:
	HandleWelcome* _handleWelcome;

};

#endif