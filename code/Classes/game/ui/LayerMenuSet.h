#ifndef __LAYER_MENU_SET_H__
#define __LAYER_MENU_SET_H__

#include "cocos2d.h"
#include "common/basic/StateCallback.h"
#include "ILayerMenuSet.h"

enum class StateLayerMenuSet
{
	DEFAULT,
	CREATE_SKIN,
	ADD_EVENT,
	PLAY_ANIMATION
};

class LayerMenuSetModel : public cocos2d::Ref
{
public:
	CREATE_FUNC(LayerMenuSetModel);

	LayerMenuSetModel();
	~LayerMenuSetModel();

	virtual bool init();

public://State
	const StateLayerMenuSet& getState() const { return _stateCallback.getState(); }
	void setState(const StateLayerMenuSet& state) { _stateCallback.setState(state); }
	StateCallback<StateLayerMenuSet>& getStateCallback() { return _stateCallback; }
private:
	StateCallback<StateLayerMenuSet> _stateCallback;

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

class LayerMenuSetHandle : public cocos2d::Ref
{
public:
	CREATE_FUNC(LayerMenuSetHandle);

	LayerMenuSetHandle();
	~LayerMenuSetHandle();

	virtual bool init();

	void attachStateCallback();

	void update(float delta);

public://skin
	void createSkin();

public://event
	void addEvent();
	void onTouchBtnContinue(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);//
	void onTouchBtnSaveLoad(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);//
	void onTouchBtnSetting(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);//

public://animation
	void playAnimation();

public://view
	CC_SYNTHESIZE(ILayerMenuSet*, _view, View);

public://model
	CC_SYNTHESIZE_READONLY(LayerMenuSetModel*, _model, Model);

};

class LayerMenuSet : public cocos2d::Layer, ILayerMenuSet
{
public:
	CREATE_FUNC(LayerMenuSet);

	LayerMenuSet();
	~LayerMenuSet();

	virtual bool init();
	virtual void update(float delta);

	virtual void addLayer(cocos2d::Layer* layer);
	virtual void addEvent(cocos2d::ui::Button* btn, const std::string& titleName, const cocos2d::ui::Widget::ccWidgetTouchCallback& onTouch);
	virtual void playAnimation(cocos2d::Layer* layer, cocos2d::Action* action);

	CC_SYNTHESIZE_READONLY(LayerMenuSetHandle*, _handle, Handle);

};

#endif
