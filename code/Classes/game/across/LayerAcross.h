#ifndef __LAYER_ACROSS_H__
#define __LAYER_ACROSS_H__

#include "cocos2d.h"
#include "CricleDotLine.h"

enum class StateLayerAcross
{
	DEFAULT,
	UNINITIALIZED,
	INITIALIZED,
	CREATEING,
};

class LayerAcrossModel : public cocos2d::Ref
{
public:
	CREATE_FUNC(LayerAcrossModel);

	LayerAcrossModel();
	~LayerAcrossModel();

	virtual bool init();

	//state
private:
	CC_SYNTHESIZE_PASS_BY_REF(StateLayerAcross, _state, State);
	
	//listener
public:
	cocos2d::EventListenerTouchOneByOne* getListener();
	void setListenerNullptr();
private:
	cocos2d::EventListenerTouchOneByOne* _listener;

	//cricledotline
public:
	CricleDotLine* getCricleDotLine();
	void createCricleDotLine();
	void deleteCricleDotLine();
private:
	void pushCricleDotLine(CricleDotLine* cdl);
	void popCricleDotLine();

	cocos2d::Vector<CricleDotLine*> _vecCricleDotLine;

	//acrossobject
public:
	CC_SYNTHESIZE(bool, _isTest, Test);
	CC_SYNTHESIZE_READONLY(bool, _isNumSizeSet, IsNumSizeSet);
	CC_SYNTHESIZE_READONLY(int, _numRowAcrossObject, NumRowAcrossObject);
	CC_SYNTHESIZE_READONLY(int, _numColumnAcrossObject, NumColumnAcrossObject);
	CC_SYNTHESIZE_READONLY_PASS_BY_REF(cocos2d::Size, _sizeAcrossObject, SizeAcrossObject);
	CC_SYNTHESIZE_READONLY_PASS_BY_REF(cocos2d::Vector<cocos2d::Node*>, _vecAcrossObject, AcrossObjects);
	void setAcrossObjectNumSize(const int& numRow, const int& numColumn, const cocos2d::Size& size);
	void createAcorssObjects();
	void clearAcrossObjects();
private:

};

class ILayerAcross
{
public:
	virtual void setContentSizeByAcrossObject(const cocos2d::Size& size) {}
	virtual void addEvent(cocos2d::EventListenerTouchOneByOne* listener) {}
	virtual void removeEvent(cocos2d::EventListenerTouchOneByOne* listener) {}
	virtual void addNodeTo(cocos2d::Node* node, const cocos2d::Vec2& postion) {}
	virtual void refreshLine(cocos2d::Sprite* line, const float& rotation, const float& scaleX) {}

};

class LayerAcrossHandle : public cocos2d::Ref
{
public:
	CREATE_FUNC(LayerAcrossHandle);

	LayerAcrossHandle();
	~LayerAcrossHandle();

	virtual bool init();

	void update(float delta);

	//uninitialized
public:
	void addEvent();
private:
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event);

	//initialized
public:
	void initialized();
	
	//creating
public:
	void creating();

	//model
public:
	CC_SYNTHESIZE_READONLY(LayerAcrossModel*, _model, Model);
private:
	
	//view
public:
	void setView(ILayerAcross* val) { _view = val; }
private:
	ILayerAcross* _view;

};

class LayerAcross : public cocos2d::Layer, ILayerAcross
{
public:
	CREATE_FUNC(LayerAcross);

	LayerAcross();
	~LayerAcross();

	virtual bool init();

	virtual void update(float delta);

	virtual void setContentSizeByAcrossObject(const cocos2d::Size& size);
	virtual void addEvent(cocos2d::EventListenerTouchOneByOne* listener);
	virtual void removeEvent(cocos2d::EventListenerTouchOneByOne* listener);
	virtual void addNodeTo(cocos2d::Node* node, const cocos2d::Vec2& postion);
	virtual void refreshLine(cocos2d::Sprite* line, const float& rotation, const float& scaleX);

	CC_SYNTHESIZE_READONLY(LayerAcrossHandle*, _handle, Handle);
private:

};

#endif
