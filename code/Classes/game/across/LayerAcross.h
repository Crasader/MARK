#ifndef __LAYER_ACROSS_H__
#define __LAYER_ACROSS_H__

#include "cocos2d.h"
#include "CricleDotLine.h"
#include "common/stateCallback/StateCallback.h"
#include <vector>

#define EVENT_LAYER_ACROSS_SELECTED "event_layer_across_selected"

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

public://state
	const StateLayerAcross & getState() const { return _stateCallback.getState(); }
	void setState(const StateLayerAcross& val) { _stateCallback.setState(val); }
	StateCallback<StateLayerAcross>& getStateCallback() { return _stateCallback; }
private:
	StateCallback<StateLayerAcross> _stateCallback;
	
	//listener
public:
	cocos2d::EventListenerTouchOneByOne* getListener();
	void setListenerNullptr();
private:
	cocos2d::EventListenerTouchOneByOne* _listener;

	//cricledotline
public:
	CricleDotLine* getCricleDotLine();
	CricleDotLine* getCricleDotLinePrevious();
	CricleDotLine* createCricleDotLine();
	void deleteCricleDotLine();
	void clearCricleDotLine();
private:
	cocos2d::Vector<CricleDotLine*> _vecCricleDotLine;

	//acrossobject
public:
	void setAcrossObjectNumSize(const int& numRow, const int& numColumn, const cocos2d::Size& size, const float& rowInterval, const float& columnInterval);
	void createAcorssObjects();
	void clearAcrossObjects();
	cocos2d::Node* getAcrossObject(const int& index);
	int getIndexOfVecAcrossObjects(const cocos2d::Vec2& location);

	CC_SYNTHESIZE(bool, _isTest, Test);
	CC_SYNTHESIZE_READONLY(int, _numRowAcrossObject, NumRowAcrossObject);
	CC_SYNTHESIZE_READONLY(int, _numColumnAcrossObject, NumColumnAcrossObject);
	CC_SYNTHESIZE_READONLY(float, _rowInterval, RowInterval);
	CC_SYNTHESIZE_READONLY(float, _columnInterval, ColumnInterval);
	CC_SYNTHESIZE_READONLY_PASS_BY_REF(cocos2d::Size, _sizeAcrossObject, SizeAcrossObject);
	CC_SYNTHESIZE_READONLY(bool, _isNumSizeSet, IsNumSizeSet);
	CC_SYNTHESIZE_READONLY_PASS_BY_REF(cocos2d::Vector<cocos2d::Node*>, _vecAcrossObject, AcrossObjects);
private:
	//
public:
	bool getIsAcrossed(const int& index);//AcrossObject
	void setIsAcrossed(const int& index, const bool& val);
protected:
	std::vector<bool> _vecIsAcrossedAcrossObject;
	//Num of result
public:
	bool getIsResultConfirmed();
	CC_SYNTHESIZE(int, _numOfResult, NumOfResult);

};

class ILayerAcross
{
public:
	virtual void setContentSizeByAcrossObject(const cocos2d::Size& size) {}
	virtual void addEvent(cocos2d::EventListenerTouchOneByOne* listener) {}
	virtual void removeEvent(cocos2d::EventListenerTouchOneByOne* listener) {}
	virtual void addNodeTo(cocos2d::Node* node, const cocos2d::Vec2& postion) {}

};

class LayerAcrossHandle : public cocos2d::Ref
{
public:
	CREATE_FUNC(LayerAcrossHandle);

	LayerAcrossHandle();
	~LayerAcrossHandle();

	virtual bool init();

	void attachStateCallback();

	void update(float delta);

	//initialize
public:
	void initialize();
private:
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event);
	
	void addCricleDotLine(const int& index, const cocos2d::Vec2& location);
	void removeCricleDotLine(const bool& isRemoveAll = false);
	void setLineLocationByPreviousCDL();
	void confirmCricleDotLine();

	//initialized
public:
	bool initializedCheck(float delta);
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

	CC_SYNTHESIZE_READONLY(LayerAcrossHandle*, _handle, Handle);
private:

};

#endif
