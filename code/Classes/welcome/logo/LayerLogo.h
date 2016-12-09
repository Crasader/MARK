#ifndef __LAYER_LOGO_H__
#define __LAYER_LOGO_H__

#include "cocos2d.h"
#include "ILayerLogo.h"
#include "HandleLogo.h"

class LayerLogo : public cocos2d::Layer, ILayerLogo
{
public:
	CREATE_FUNC(LayerLogo);

	LayerLogo();
	~LayerLogo();

	virtual bool init();
	virtual void update(float delta);

	virtual void addSkin(cocos2d::Layer* skin);
	virtual void playAnimation(cocos2d::Layer* skin, cocos2d::Action* action);//²¥·Å¶¯»­

private:
	HandleLogo* _handleLogo;

};

#endif