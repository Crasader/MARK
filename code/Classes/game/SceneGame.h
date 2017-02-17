#ifndef __SCENE_GAME_H__
#define __SCENE_GAME_H__

#include "cocos2d.h"
#include "common/stateCallback/StateCallback.h"
#include "common/observer/Observer.h"

enum class StateGame
{
	DEFAULT,
	INIT_RODOM_SEED,
	ATTACH_OBSERVER,
	DEAL_DATA_BASE,
	UNLOAD_RES,
	LOADED_RES,
	CREATE_ENTITY,
	CREATED_ENTITY
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

	void dealDatabase();//获取（构建）数据库

public://state
	const StateGame & getState() const { return _stateCallback.getState(); }
	void setState(const StateGame& val) { _stateCallback.setState(val); }
	StateCallback<StateGame>& getStateCallback() { return _stateCallback; }
private:
	StateCallback<StateGame> _stateCallback;

public://
	CC_SYNTHESIZE(bool, _isLoadedRes, IsLoadedRes);

public:
	CC_SYNTHESIZE(bool, _isCreatedEntity, IsCreatedEntity);

public://layers
	cocos2d::Layer* getLayer(const TypeLayerInGame& type);
	void setLayerPostion(const TypeLayerInGame& type, const cocos2d::Vec2& postion);
	void setLayerNullptr(const TypeLayerInGame& type);

	void setLayerAcrossNumSize(const int& numRow, const int& numColumn, const cocos2d::Size& size, const bool& isTest = false);
private:
	cocos2d::Layer* createLayerByType(const TypeLayerInGame& type);
	bool insertLayerByType(const TypeLayerInGame& type, cocos2d::Layer* layer);
	bool eraseLayerByType(const TypeLayerInGame& type);
	cocos2d::Layer* getLayerByType(const TypeLayerInGame& type);

	cocos2d::Map<TypeLayerInGame, cocos2d::Layer*> _dicLayers;

public://listener
	CC_SYNTHESIZE(cocos2d::EventListenerCustom*, _listener, ListenerLayerResLoadLoaded);

};

class ISceneGame
{
public:
	virtual void addLayer(cocos2d::Layer* layer) {}
	virtual void removeLayer(cocos2d::Layer* layer) {}

};

class SceneGameHandle : public cocos2d::Ref, Observer
{
public:
	CREATE_FUNC(SceneGameHandle);

	SceneGameHandle();
	~SceneGameHandle();

	virtual bool init();

	void attachStateCallback();

	void update(float delta);

private:
	void initRandomSeed();
	void attachOvserver();
	void dealDatabase();

private://res
	void loadRes();
	void addEventLayerResLoadLoaded();
	void removeEventLayerResLoadLoaded();
	void onEventLayerResLoadLoaded(cocos2d::EventCustom* event);
	bool loadedResCheck(float delta);
	void loadedRes();

private://
	void createEntity();
	bool createdEntityCheck(float delta);
	void createdEntity();

public://observer
	virtual void updateBySubject(va_list values);
private:
	void createLayer(const TypeLayerInGame& type, const std::function<void()>& extraFunc = nullptr);
	void deleteLayer(const TypeLayerInGame& type, const std::function<void()>& extraFunc = nullptr);
	void extraFuncCreateLayerAcross(/*va_list values*/);//添加九宫格滑动层

public://view
	CC_SYNTHESIZE(ISceneGame*, _view, View);

public://model
	CC_SYNTHESIZE_READONLY(SceneGameModel*, _model, Model);

};

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
	SceneGameHandle* _handle;

};

#endif
