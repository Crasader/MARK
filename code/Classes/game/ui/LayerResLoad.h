#pragma execution_character_set("utf-8")

#ifndef __GAME_UI_LAYER_RES_LOAD_H__
#define __GAME_UI_LAYER_RES_LOAD_H__

#include "cocos2d.h"
#include "ILayerResLoad.h"
#include "HandleResLoad.h"

NS_BEGIN_UI_COMMON

class LayerResLoad : public cocos2d::Layer, ILayerResLoad
{
public:
	CREATE_FUNC(LayerResLoad);

public:
	LayerResLoad();
	~LayerResLoad();

	virtual bool init();
	virtual void update(float delta);
	virtual void createSkin();
	virtual void playLoad();
	virtual void stopLoad();

private:
	HandleResLoad* _handleImageLoad;

	cocos2d::Node* _skin;

	const std::string SPRITELOAD = "spriteLoad";

};

NS_END_END

#endif