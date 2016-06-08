#ifndef __WELCOME_LOGO_HANDLE_LOGO_H__
#define __WELCOME_LOGO_HANDLE_LOGO_H__

#include "cocos2d.h"
#include "welcome/ISceneWelcome.h"
#include "ILayerLogo.h"
#include "ModelLogo.h"

class HandleLogo : public cocos2d::Ref
{
public:
	CREATE_FUNC(HandleLogo);

	HandleLogo();
	~HandleLogo();

	virtual bool init();

	void update(float delta);

	bool isStateLogoBeLogoOver();

	void setHandleWelcome(ISceneWelcome* val) { _sceneWelcome = val; }
	void setLayerLogo(ILayerLogo* val) { _layerLogo = val; }
	
private:
	ISceneWelcome* _sceneWelcome;

	ILayerLogo* _layerLogo;
	ModelLogo* _modelLogo;

};

#endif