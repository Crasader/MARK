#ifndef __GAME_HANDLE_GAME_H__
#define __GAME_HANDLE_GAME_H__

#include "cocos2d.h"
#include "common/observer/Observer.h"
#include "ISceneGame.h"
#include "ModelGame.h"

class HandleGame : public cocos2d::Ref, Observer
{
public:
	CREATE_FUNC(HandleGame);

	HandleGame();
	~HandleGame();

	virtual bool init();
	virtual void updateBySubject(va_list values);

	void crateDatabase();

	CC_SYNTHESIZE(ISceneGame*, _sceneMain, SceneGame);
	CC_SYNTHESIZE_READONLY(ModelGame*, _modelGame, ModelGame);

private:

};

#endif