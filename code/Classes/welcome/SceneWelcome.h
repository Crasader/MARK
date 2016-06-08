#ifndef __WELCOME_SCENE_WELCOME_H__
#define __WELCOME_SCENE_WELCOME_H__

#include "cocos2d.h"
#include "ISceneWelcome.h"
#include "HandleWelcome.h"
#include "logo/LayerLogo.h"

class SceneWelcome : public cocos2d::Scene,ISceneWelcome
{
public:
	CREATE_FUNC(SceneWelcome);

	SceneWelcome();
	~SceneWelcome();

	virtual bool init();
	virtual void update(float delta);

	virtual void layerLogoAdd();
	virtual void layerLogoRemove();

private:
	HandleWelcome* _handleWelcome;

	LayerLogo* _layerLogo;

};

#endif