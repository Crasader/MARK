#ifndef __HANDLE_GAME_H__
#define __HANDLE_GAME_H__

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

	void update(float delta);

	virtual void updateBySubject(va_list values);

	CC_SYNTHESIZE(ISceneGame*, _sceneGame, SceneGame);
	CC_SYNTHESIZE_READONLY(ModelGame*, _modelGame, ModelGame);

private:
	void initRandomSeed();
	void attachOvserver();
	void getDatabase();

	void createLayer(const TypeLayer& type);
	void deleteLayer(const TypeLayer& type);

	void loadRes();
	void addEventLayerResLoadLoaded();
	void removeEventLayerResLoadLoaded();
	void onEventLayerResLoadLoaded(cocos2d::EventCustom* event);
	void loadedRes();
	
};

#endif