#ifndef __I_LAYER_LOGO_H__
#define __I_LAYER_LOGO_H__

class ILayerLogo
{
public:
	virtual void addSkin(cocos2d::Layer* skin) {}
	virtual void playAnimation(cocos2d::Layer* skin, cocos2d::Action* action) {}//²¥·Å¶¯»­

};

#endif