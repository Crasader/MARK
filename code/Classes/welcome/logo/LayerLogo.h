#ifndef __WELCOME_LOGO_LAYER_LOGO_H__
#define __WELCOME_LOGO_LAYER_LOGO_H__

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

	virtual void createSkin();
	virtual void playAnimation();

private:
	HandleLogo* _handleLogo;

	cocos2d::Layer* _skin;
	const std::string ANIMATION_NAME = "animation0";

};

#endif