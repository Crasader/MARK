#ifndef __MODEL_GAME_H__
#define __MODEL_GAME_H__

#include "cocos2d.h"

enum class StateGame
{
	DEFAULT,
	INIT_RODOM_SEED,
	ATTACH_OBSERVER,
	GET_DATA_BASE,
	UNLOAD_RES,
	LOADING_RES,
	LOADED_RES
};

enum class TypeLayer
{
	RESLOAD,
	ENTITY,
	ACROSS,
	MENU_START,
	MENU_SYSTEM
};

class ModelGame : public cocos2d::Ref
{
public:
	CREATE_FUNC(ModelGame);

	ModelGame();
	~ModelGame();

	virtual bool init();

	void getDatabase();//获取（构建）数据库

	cocos2d::Layer* getLayer(const TypeLayer& type);
	void setLayerNullptr(const TypeLayer& type);

	CC_SYNTHESIZE(cocos2d::EventListenerCustom*, _listenerLayerResLoadLoaded, ListenerLayerResLoadLoaded);
	CC_SYNTHESIZE(StateGame, _state, StateGame);

private:
	cocos2d::Layer* createLayerByType(const TypeLayer& type);
	bool insertLayerByType(const TypeLayer& type, cocos2d::Layer* layer);
	bool eraseLayerByType(const TypeLayer& type);
	cocos2d::Layer* getLayerByType(const TypeLayer& type);

	cocos2d::Map<TypeLayer, cocos2d::Layer*> _dicLayers;

};

#endif