#ifndef __WELCOME_LOGO_I_LAYER_LOGO_H__
#define __WELCOME_LOGO_I_LAYER_LOGO_H__

class ILayerLogo
{
public:
	virtual void createSkin() {}//构造皮肤
	virtual void playAnimation() {}//播放动画
	virtual bool isLogoPlayOver() { return false; }//是否LOGO结束

};

#endif