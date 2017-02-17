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
	LOADED_RES,
	ADD_ACROSS,
	REMOVE_ACROSS,
};

enum class TypeLayerInGame
{
	RESLOAD,
	ENTITY,
	ACROSS,
	MENU_START,
	MENU_SYSTEM
};

class SceneGameModel : public cocos2d::Ref
{
public:
	CREATE_FUNC(SceneGameModel);

	SceneGameModel();
	~SceneGameModel();

	virtual bool init();

	void getDatabase();//获取（构建）数据库

	cocos2d::Layer* getLayer(const TypeLayerInGame& type);
	void setLayerPostion(const TypeLayerInGame& type, const cocos2d::Vec2& postion);
	void setLayerNullptr(const TypeLayerInGame& type);

	void setLayerAcrossNumSize(const int& numRow, const int& numColumn, const cocos2d::Size& size);
	void setLayerAcrossIsTest(const bool& isTest);

	CC_SYNTHESIZE(cocos2d::EventListenerCustom*, _listenerLayerResLoadLoaded, ListenerLayerResLoadLoaded);
	CC_SYNTHESIZE(StateGame, _state, StateGame);

private:
	cocos2d::Layer* createLayerByType(const TypeLayerInGame& type);
	bool insertLayerByType(const TypeLayerInGame& type, cocos2d::Layer* layer);
	bool eraseLayerByType(const TypeLayerInGame& type);
	cocos2d::Layer* getLayerByType(const TypeLayerInGame& type);

	cocos2d::Map<TypeLayerInGame, cocos2d::Layer*> _dicLayers;

};

#endif