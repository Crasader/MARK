#ifndef __LAYER_MENU_SYSTEM_H__
#define __LAYER_MENU_SYSTEM_H__

#include "cocos2d.h"
#include "ui/UIWidget.h"
#include "common/stateCallback/StateCallback.h"
#include "ui/UIButton.h"

enum class StateLayerMenuSystem
{
	DEFAULT,
	CREATE_SKIN,
	ADD_EVENT,
	PLAY_ANIMATION
};

class LayerMenuSystemModel : public cocos2d::Ref
{
public:
	CREATE_FUNC(LayerMenuSystemModel);

	LayerMenuSystemModel();
	~LayerMenuSystemModel();

	virtual bool init();

public://State
	const StateLayerMenuSystem& getState() const { return _stateCallback.getState(); }
	void setState(const StateLayerMenuSystem& state) { _stateCallback.setState(state); }
	StateCallback<StateLayerMenuSystem>& getStateCallback() { return _stateCallback; }
private:
	StateCallback<StateLayerMenuSystem> _stateCallback;

public://skin
	cocos2d::Layer* getSkin();
	const cocos2d::Vector<cocos2d::ui::Button*>& getVecBtns();
private:
	cocos2d::Layer *_skin;
	cocos2d::Vector<cocos2d::ui::Button*> _vecBtns;

public://animation
	cocos2d::Action* getAnimation();
	CC_SYNTHESIZE_READONLY(bool, _isAnimationPlayOver, AnimationPlayOver);

};

class ILayerMenuSystem
{
public:
	virtual void addLayer(cocos2d::Layer* layer) {}
	virtual void addEvent(cocos2d::ui::Button* btn, const std::string& titleName, const cocos2d::ui::Widget::ccWidgetTouchCallback& onTouch) {}
	virtual void playAnimation(cocos2d::Layer* layer, cocos2d::Action* action) {}
};

class LayerMenuSystemHandle : public cocos2d::Ref
{
public:
	CREATE_FUNC(LayerMenuSystemHandle);

	LayerMenuSystemHandle();
	~LayerMenuSystemHandle();

	virtual bool init();

	void attachStateCallback();

	void update(float delta);

public://skin
	void createSkin();
	
public://event
	void addEvent();
	void onTouchBtnSetting(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);//开关游戏设置层
	void onTouchBtnSounds(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);//开关游戏声效

public://animation
	void playAnimation();

public://view
	CC_SYNTHESIZE(ILayerMenuSystem*, _view, View);

public://model
	CC_SYNTHESIZE_READONLY(LayerMenuSystemModel*, _model, Model);

};

class LayerMenuSystem : public cocos2d::Layer, ILayerMenuSystem
{
public:
	CREATE_FUNC(LayerMenuSystem);

	LayerMenuSystem();
	~LayerMenuSystem();

	virtual bool init();
	virtual void update(float delta);

	virtual void addLayer(cocos2d::Layer* layer);
	virtual void addEvent(cocos2d::ui::Button* btn, const std::string& titleName, const cocos2d::ui::Widget::ccWidgetTouchCallback& onTouch);
	virtual void playAnimation(cocos2d::Layer* layer, cocos2d::Action* action);

	CC_SYNTHESIZE_READONLY(LayerMenuSystemHandle*, _handle, Handle);

};

#endif