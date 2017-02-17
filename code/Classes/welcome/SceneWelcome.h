#ifndef __SCENE_WELCOME_H__
#define __SCENE_WELCOME_H__

#include "cocos2d.h"
#include "common/stateCallback/StateCallback.h"

enum class StateWelcome
{
	DEFAULT,
	UNPLAY_LOGO,
	PLAYED_LOGO,
	REPLACE_SCENE
};

enum class TypeLayerInWelcome
{
	LOGO,

};

class SceneWelcomeModel : public cocos2d::Ref
{
public:
	CREATE_FUNC(SceneWelcomeModel);

	SceneWelcomeModel();
	~SceneWelcomeModel();

	virtual bool init();

public://StateWelcomeCallback
	const StateWelcome& getState() const { return _stateCallback.getState(); }
	void setState(const StateWelcome& state) { _stateCallback.setState(state); }
	StateCallback<StateWelcome>& getStateCallback() { return _stateCallback; }
private:
	StateCallback<StateWelcome> _stateCallback;

public://isLogoPlayOver
	CC_SYNTHESIZE(bool, _isLogoPlayOver, IsLogoPlayOver);

public://layers
	cocos2d::Layer* getLayer(const TypeLayerInWelcome& type);
	void setLayerNullptr(const TypeLayerInWelcome& type);
private:
	cocos2d::Layer* createLayerByType(const TypeLayerInWelcome& type);
	bool insertLayerByType(const TypeLayerInWelcome& type, cocos2d::Layer* layer);
	bool eraseLayerByType(const TypeLayerInWelcome& type);
	cocos2d::Layer* getLayerByType(const TypeLayerInWelcome& type);

	cocos2d::Map<TypeLayerInWelcome, cocos2d::Layer*> _dicLayers;

public://ListenerLayerLogoOver
	CC_SYNTHESIZE(cocos2d::EventListenerCustom*, _listener, ListenerLayerLogoOver);
	
};

class ISceneWelcome
{
public:
	virtual void addLayer(cocos2d::Layer* layer) {}
	virtual void removeLayer(cocos2d::Layer* layer) {}
	virtual void replaceSceneToGame() {}//切换为游戏场景

};

class SceneWelcomeHandle : public cocos2d::Ref
{
public:
	CREATE_FUNC(SceneWelcomeHandle);

	SceneWelcomeHandle();
	~SceneWelcomeHandle();

	virtual bool init();

	void attachStateCallback();

	void update(float delta);

	void setView(ISceneWelcome* val) { _view = val; }

private:
	void createLayer(const TypeLayerInWelcome& type);
	void deleteLayer(const TypeLayerInWelcome& type);

	void playLogo();
	void addEventLayerLogoOver();
	void removeEventLayerLogoOver();
	void onEventLayerLogoOver(cocos2d::EventCustom* event);

	bool playedLogoCheck(float delta);
	void playedLogo();

	void replaceScene();

	ISceneWelcome* _view;
	SceneWelcomeModel* _model;

};

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

	virtual void replaceSceneToGame();//切换为游戏场景

private:
	SceneWelcomeHandle* _handle;

};

#endif