#ifndef _UI_SCENE_MAIN_H_
#define _UI_SCENE_MAIN_H_

#include "cocos2d.h"

class SceneMain : public cocos2d::Scene
{
public:
	CREATE_FUNC(SceneMain);

	SceneMain();
	~SceneMain();

	virtual bool init();

private:
	cocos2d::Scene *_skin;
};

#endif
