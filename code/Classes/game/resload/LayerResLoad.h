#pragma execution_character_set("utf-8")

#ifndef __LAYER_RES_LOAD_H__
#define __LAYER_RES_LOAD_H__

#include "cocos2d.h"
#include <string>
#include "common/bitData/BitData.h"
#include "common/stateCallback/StateCallback.h"

#define EVENT_LAYER_RES_LOAD_LOADED "event_layer_res_load_loaded"

enum class StateLayerResLoad
{
	DEFAULT,
	CREATE_SKIN,
	UNLOAD_SOUND,
	LOADING_SOUND,
	LOADED_SOUND,
	UNLOAD_IMAGE,
	LOADING_IMAGE,
	LOADED_IMAGE
};

class LayerResLoadModel : public cocos2d::Ref
{
public:
	CREATE_FUNC(LayerResLoadModel);

	LayerResLoadModel();
	~LayerResLoadModel();

	virtual bool init();

public://state
	const StateLayerResLoad & getState() const { return _stateCallback.getState(); }
	void setState(const StateLayerResLoad& val) { _stateCallback.setState(val); }
	StateCallback<StateLayerResLoad>& getStateCallback() { return _stateCallback; }
private:
	StateCallback<StateLayerResLoad> _stateCallback;

public:
	cocos2d::Node* getSkin();
	cocos2d::Node* getSpriteLoad();
	BitData* getBitData();

private:
	cocos2d::Node* _skin;
	cocos2d::Node* _spriteLoad;
	BitData* _bitData;

};

class ILayerResLoad
{
public:
	virtual void addSkin(cocos2d::Node* skin) {}
	virtual void playLoadAnimation(cocos2d::Node* node) {}//播放加载动画
	virtual void stopLoadAnimation(cocos2d::Node* node) {}//停止加载动画

};

class LayerResLoadHandle : public cocos2d::Ref
{
public:
	CREATE_FUNC(LayerResLoadHandle);

public:
	LayerResLoadHandle();
	~LayerResLoadHandle();

	virtual bool init();

	void attachStateCallback();

	void update(float delta);

	void setView(ILayerResLoad* val) { _view = val; }

private:
	void createSkin();

	void playLoadAnimation();
	void stopLoadAnimation();

	void loadSounds();
	void loadingSounds();
	void loadedSounds();

	void loadImages();
	/*加载plist或png
	fileName *.plist或*.png*/
	void asyncLoadImage(const std::string& fileName);
	void asyncLoadImageCallback(cocos2d::Texture2D* texture, const std::string& fileName, const int& bitIndex);
	void loadedImages();

	ILayerResLoad* _view;
	LayerResLoadModel* _model;

};

class LayerResLoad : public cocos2d::Layer, ILayerResLoad
{
public:
	CREATE_FUNC(LayerResLoad);

public:
	LayerResLoad();
	~LayerResLoad();

	virtual bool init();
	
	virtual void update(float delta);

	virtual void addSkin(cocos2d::Node* skin);
	virtual void playLoadAnimation(cocos2d::Node* node);//播放加载动画
	virtual void stopLoadAnimation(cocos2d::Node* node);//停止加载动画

private:
	LayerResLoadHandle* _handle;

};

#endif