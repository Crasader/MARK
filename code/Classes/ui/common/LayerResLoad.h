#pragma execution_character_set("utf-8")

#ifndef __UI_WELCOME_SCENE_WELCOME_H__
#define __UI_WELCOME_SCENE_WELCOME_H__

#include "cocos2d.h"
#include "ILayerResLoad.h"
#include "HandleResLoad.h"

NS_BEGIN_UI_COMMON

class LayerResLoad : public cocos2d::Layer, userInerface::common::ILayerResLoad
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
	const std::string SPRITELOAD = "spriteLoad";

	cocos2d::Node* _skin;

	HandleResLoad* _handleImageLoad;

};

NS_END_END

#endif