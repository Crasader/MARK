#pragma execution_character_set("utf-8")

#ifndef __LAYER_RES_LOAD_H__
#define __LAYER_RES_LOAD_H__

#include "cocos2d.h"
#include "ILayerResLoad.h"
#include "HandleResLoad.h"

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
	HandleResLoad* _handleImageLoad;

};

#endif