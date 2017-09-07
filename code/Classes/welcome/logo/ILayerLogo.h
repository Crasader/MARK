#ifndef __I_LAYER_LOGO_H__
#define __I_LAYER_LOGO_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include <string>

class ILayerLogo
{
public:
	virtual void addSkin(cocos2d::Layer* skin) {}
	virtual void playAnimation(cocos2d::Layer* skin, cocostudio::timeline::ActionTimeline* action, const std::string& animationName, const bool& isLoop) {}//²¥·Å¶¯»­

};
#endif