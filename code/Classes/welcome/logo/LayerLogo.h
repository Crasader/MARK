#ifndef __LAYER_LOGO_H__
#define __LAYER_LOGO_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "common/stateCallback/StateCallback.h"

enum class StateLayerLogo
{
	DEFAULT,
	CREATE_SKIN,
	UNPLAY_LOGO,
	PLAYING_LOGO,
	PLAYED_LOGO
};

#define LAYER_LOGO_ANIMATION_0 "animation0"

class LayerLogoModel : public cocos2d::Ref
{
public:
	CREATE_FUNC(LayerLogoModel);

	LayerLogoModel();
	~LayerLogoModel();

	virtual bool init();

public://skin
	cocos2d::Layer* getSkin();
	cocostudio::timeline::ActionTimeline* getActionTimeline();
private:
	cocos2d::Layer* _skin;

public://duration
	void addDuration(float val);
	bool isTimeOver();
private:
	float _duration;
	const float DURATION_TOTAL = 3.0f;

public://StateLayerLogoCallback
	const StateLayerLogo& getState() const { return _stateCallback.getState(); }
	void setState(const StateLayerLogo& state) { _stateCallback.setState(state); }
	StateCallback<StateLayerLogo>& getStateCallback() { return _stateCallback; }
private:
	StateCallback<StateLayerLogo> _stateCallback;

};

class ILayerLogo
{
public:
	virtual void addSkin(cocos2d::Layer* skin) {}
	virtual void playAnimation(cocos2d::Layer* skin, cocostudio::timeline::ActionTimeline* action, const std::string& animationName, const bool& isLoop) {}//播放动画

};

class LayerLogoHandle : public cocos2d::Ref
{
public:
	CREATE_FUNC(LayerLogoHandle);

	LayerLogoHandle();
	~LayerLogoHandle();

	virtual bool init();

	void attachStateCallback();

	void update(float delta);

	void setView(ILayerLogo* val) { _view = val; }

private:
	void createSkin();
	void playLogo();
	bool playingLogoCheck(float delta);
	void playingLogo();
	void playedLogo();

	ILayerLogo* _view;
	LayerLogoModel* _model;

};

class LayerLogo : public cocos2d::Layer, ILayerLogo
{
public:
	CREATE_FUNC(LayerLogo);

	LayerLogo();
	~LayerLogo();

	virtual bool init();
	virtual void update(float delta);

	virtual void addSkin(cocos2d::Layer* skin);
	virtual void playAnimation(cocos2d::Layer* skin, cocostudio::timeline::ActionTimeline* action, const std::string& animationName, const bool& isLoop);//播放动画

private:
	LayerLogoHandle* _handle;

};

#endif